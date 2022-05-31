#include <stdio.h>
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;

void display(const std::string& f)
{
    std::cout << "DISPLAYING: " << f << std::endl;
    // Read the image file as
    // imread("default.jpg");
    Mat image = imread(f, IMREAD_GRAYSCALE);
    // Error Handling
    if (image.empty()) {
        std::cout << "Image not found!" << std::endl;

        // wait for any key press
        std::cin.get();
    }

    // Show Image inside a window with
    // the name provided
    imshow("Meme", image);

    // Wait for any keystroke
    waitKey(0);
}

void display_photos(int len)
{
    // Display images
    for (int i = 1; i <= len; i++) {
        std::string out_file = "image";
        out_file += std::to_string(i);
        out_file += ".jpg";
        display(out_file);
    }
}

void display_info()
{
    std::cout << "****************************************************" << std::endl;
    std::cout << "***** LET'S DOWNLOAD SOME MEMES FROM KWEJK.PL! *****" << std::endl;
    std::cout << "****************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "CHOOSE A CATEGORY:" << std::endl;
    std::cout << "1: VARIOUS" << std::endl;
    std::cout << "2: HUMOUR" << std::endl;
    std::cout << "3: MEME" << std::endl;
    std::cout << "4: COMIC BOOKS" << std::endl;
    std::cout << "5: TITBITS " << std::endl;
    std::cout << "6: POLITICS" << std::endl;
    std::cout << std::endl;

}

void download_image(const std::string& image_link, const int& value)
{
    // Output file will be named like "image[val].jpg
    std::string out_file{ "image" };
    out_file += std::to_string(value);
    out_file += ".jpg";

    const char* out_file_cchar = out_file.c_str();
    const char* img_link_cchar = image_link.c_str();
    // Need to open file in binary mode
    FILE* file = fopen(out_file_cchar, "wb");

    // CURL downloading image
    CURL* easyhandle = curl_easy_init();
    curl_easy_setopt(easyhandle, CURLOPT_URL, img_link_cchar);
    curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, file);
    curl_easy_perform(easyhandle);
    curl_easy_cleanup(easyhandle);

    // Closing output file
    fclose(file);
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL* curl { curl_easy_init() };
    CURLcode res {};

    if (curl) {

        display_info();

        std::string readBuffer{};
        std::string url{};
        int option{};
        std::cout << ": ";
        std::cin >> option;

        std::cout << std::endl;

        switch (option)
        {
            case 1:
                std::cout << "You've chosen category: VARIOUS!" << std::endl;
                url = "https://kwejk.pl/";
                break;
            case 2:
                std::cout << "You've chosen category: HUMOUR!" << std::endl;
                url = "https://kwejk.pl/kategoria/humor";
                break;
            case 3:
                std::cout << "You've chosen category: MEME!" << std::endl;
                url = "https://kwejk.pl/kategoria/meme";
                break;
            case 4:
                std::cout << "You've chosen category: COMIC BOOKS!" << std::endl;
                url = "https://kwejk.pl/kategoria/komiksy";
                break;
            case 5:
                std::cout << "You've chosen category: TITBITS!" << std::endl;
                url = "https://kwejk.pl/kategoria/ciekawostki";
                break;
            case 6:
                std::cout << "You've chosen category: POLITICS!" << std::endl;
                url = "https://kwejk.pl/kategoria/polityka";
                break;
            default:
                std::cout << "Wrong option!" << std::endl;
                return 0;
        }

        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.ignore(10, '\n');
        std::cin.get();

        // need char* instead of str::string - library requirement
        const char* url_cchar = url.c_str();

        curl_easy_setopt(curl, CURLOPT_URL, url_cchar);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        // Looking for links to images - using vector to store them.
        std::vector <std::string> images{};
        int i{};
        char c{ '"' };
        size_t nPos = readBuffer.find("data-image=", 0);
        while (nPos != std::string::npos)
        {
            std::string image_link;
            i = static_cast<int>(nPos);
            i += 12;
            while (readBuffer[i] != c)
            {
                image_link += readBuffer[i];
                i++;
            }
            images.push_back(image_link);
            nPos = readBuffer.find("data-image=", nPos + 1);
        }

        // Download images - saved in images vector
        std::cout << "Downloading memes..." << std::endl;

        i = 1;
        for (const auto& image : images)
        {
            // Show link which is being downloaded and download it.
            std::cout << image << std::endl;
            download_image(image, i);
            i++;
        }

        std::cout << "DOWNLOADED SUCCESSFULLY!" << std::endl;

        std::cout << std::endl;
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.get();

        // Display images if wanted
        char o{};
        std::cout << "Would you like to display memes? (Y/N)" << std::endl;
        std::cin >> o;
        if (o == 'Y' || o == 'y')
        {
            display_photos(images.size());
        }

        // Finish app
        std::cout << "Closing app..." << std::endl;
    }
    return 0;
}