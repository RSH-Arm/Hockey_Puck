#include <opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/tracking.hpp"

#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;
// "C:\\Users\\Colonel\\Desktop\\Detect\\Screenshot_1.png"

//int main() {
//    // read the image
//    Mat image = imread("C:\\Users\\Colonel\\Desktop\\Detect\\Screenshot_1.png");
//    // convert the image to grayscale format
//    Mat img_gray;
//    cvtColor(image, img_gray, COLOR_BGR2GRAY);
//    // apply binary thresholding
//    Mat thresh;
//    threshold(img_gray, thresh, 50, 255, THRESH_BINARY);
//    imshow("Binary mage", thresh);
//    waitKey(0);
//    imwrite("image_thres1.jpg", thresh);
//    destroyAllWindows();
//
//    // detect the contours on the binary image using cv2.CHAIN_APPROX_NONE
//    vector<vector<Point>> contours;
//    vector<Vec4i> hierarchy;
//    findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
//
//    std::cout << "contours - " << contours.size() << "\nhierarchy - " << hierarchy.size() << endl;
//    // нарисуйте контуры на исходном изображении
//    Mat image_copy = image.clone();
//    drawContours(image_copy, contours, -1, Scalar(0, 255, 0), 2);
//    imshow("None approximation", image_copy);
//    waitKey(0);
//    imwrite("contours_none_image1.jpg", image_copy);
//    destroyAllWindows();
//
//
//    // Теперь давайте попробуем с помощью CHAIN_APPROX_SIMPLE
//    // определить контуры на двоичном изображении с помощью cv2.CHAIN_APPROX_NONE
//    vector<vector<Point>> contours1;
//    vector<Vec4i> hierarchy1;
//    findContours(thresh, contours1, hierarchy1, RETR_TREE, CHAIN_APPROX_SIMPLE);
//
//    std::cout << "contours - " << contours1.size() << "\nhierarchy - " << hierarchy1.size() << endl;
//    // нарисуйте контуры на исходном изображении
//    Mat image_copy1 = image.clone();
//    drawContours(image_copy1, contours1, -1, Scalar(0, 255, 0), 2);
//    imshow("Simple approximation", image_copy1);
//    waitKey(0);
//    imwrite("contours_simple_image1.jpg", image_copy1);
//    destroyAllWindows();
//
//    // использование правильного изображения для визуализации CHAIN_APPROX_SIMPLE
//    Mat image1 = imread("../../input/image_2.jpg");
//    Mat img_gray1;
//    cvtColor(image1, img_gray1, COLOR_BGR2GRAY);
//    Mat thresh1;
//    threshold(img_gray1, thresh1, 150, 255, THRESH_BINARY);
//    vector<vector<Point>> contours2;
//    vector<Vec4i> hierarchy2;
//    findContours(thresh1, contours2, hierarchy2, RETR_TREE, CHAIN_APPROX_NONE);
//    Mat image_copy2 = image1.clone();
//    drawContours(image_copy2, contours2, -1, Scalar(0, 255, 0), 2);
//    imshow("None approximation", image_copy2);
//    waitKey(0);
//    imwrite("contours_none_image1.jpg", image_copy2);
//    destroyAllWindows();
//    Mat image_copy3 = image1.clone();
//    for (int i = 0; i < contours2.size(); i = i + 1) {
//        for (int j = 0; j < contours2[i].size(); j = j + 1) {
//            circle(image_copy3, (contours2[i][0], contours2[i][1]), 2,
//                Scalar(0, 255, 0), 2);
//        }
//    }
//    imshow("CHAIN_APPROX_SIMPLE Point only", image_copy3);
//    waitKey(0);
//    imwrite("contour_point_simple.jpg", image_copy3);
//    destroyAllWindows();
//}

//int main() {
//    /*
//    Contour detection and drawing using different extraction modes to complement
//    the understanding of hierarchies
//    */
//    Mat image2 = imread("C:\\Users\\Colonel\\Desktop\\Detect\\Screenshot_1.png");
//    Mat img_gray2;
//    cvtColor(image2, img_gray2, COLOR_BGR2GRAY);
//    Mat thresh2;
//    threshold(img_gray2, thresh2, 50, 255, THRESH_BINARY);
//
//    vector<vector<Point>> contours3;
//    vector<Vec4i> hierarchy3;
//    findContours(thresh2, contours3, hierarchy3, RETR_LIST, CHAIN_APPROX_NONE);
//    Mat image_copy4 = image2.clone();
//    drawContours(image_copy4, contours3, -1, Scalar(0, 255, 0), 2);
//    imshow("LIST", image_copy4);
//    waitKey(0);
//    imwrite("contours_retr_list.jpg", image_copy4);
//    destroyAllWindows();
//
//    vector<vector<Point>> contours4;
//    vector<Vec4i> hierarchy4;
//    findContours(thresh2, contours4, hierarchy4, RETR_EXTERNAL, CHAIN_APPROX_NONE);
//    Mat image_copy5 = image2.clone();
//    drawContours(image_copy5, contours4, -1, Scalar(0, 255, 0), 2);
//    imshow("EXTERNAL", image_copy5);
//    waitKey(0);
//    imwrite("contours_retr_external.jpg", image_copy5);
//    destroyAllWindows();
//
//    vector<vector<Point>> contours5;
//    vector<Vec4i> hierarchy5;
//    findContours(thresh2, contours5, hierarchy5, RETR_CCOMP, CHAIN_APPROX_NONE);
//    Mat image_copy6 = image2.clone();
//    drawContours(image_copy6, contours5, -1, Scalar(0, 255, 0), 2);
//    imshow("EXTERNAL", image_copy6);
//    waitKey(0);
//    imwrite("contours_retr_ccomp.jpg", image_copy6);
//    destroyAllWindows();
//
//    vector<vector<Point>> contours6;
//    vector<Vec4i> hierarchy6;
//    findContours(thresh2, contours6, hierarchy6, RETR_TREE, CHAIN_APPROX_NONE);
//    Mat image_copy7 = image2.clone();
//    drawContours(image_copy7, contours6, -1, Scalar(0, 255, 0), 2);
//    imshow("EXTERNAL", image_copy7);
//    waitKey(0);
//    imwrite("contours_retr_tree.jpg", image_copy7);
//    destroyAllWindows();
//}


//int main() {
//
//    Mat image2 = imread("C:\\Users\\Colonel\\Desktop\\Detect\\Screenshot_1.png");
//    Mat img_gray2;
//    cvtColor(image2, img_gray2, COLOR_BGR2GRAY);
//    Mat thresh2;
//    threshold(img_gray2, thresh2, 50, 255, THRESH_BINARY);
//
//    vector<vector<Point>> contours;
//    vector<Vec4i> hierarchy;
//    findContours(thresh2, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
//    
//    // Get internal contours
//    Mat outContours = img_gray2.clone();
//    
//    vector<vector<Point>> internalContours;
//    for (size_t i = 0; i < contours.size(); ++i) {
//        // Найдите ориентацию: CW или CC
//        double area = contourArea(contours[i], true);
//        if (area >= 0) {
//            // Внутренний контур
//            internalContours.push_back(contours[i]);
//
//            // Рисуйте разными цветами
//            drawContours(outContours, contours, i, Scalar(rand() & 255, rand() & 255, rand() & 255),2);
//        }
//    }
//
//    // Get circles 
//    int ii = 1;
//    Mat outContours_ = image2.clone();
//    for (const auto& cnt : internalContours) {
//        Point2f center;
//        float radius;
//        minEnclosingCircle(cnt, center, radius);
//        radius = ceil(radius);
//        if (radius >= 40)
//        {
//           // auto T = minAreaRect(cnt);
//          //  boxPoints(minAreaRect(cnt), outContours_);
//            /*cout << "[" << ii << "] " << radius << endl;
//            ii++;*/
//            // Draw circle in blue
//            Rect2f a{ (center.x - 45), (center.y - 45), 90, 90 };
//            rectangle(outContours_, a, Scalar(255, 0, 0)); // boundingRect(cnt)
//            circle(outContours_, center, 45, Scalar(255, 0, 0));
//        }
//    }
//
//  //  drawContours(img_gray2, contours, -1, Scalar(0, 255, 0), 2);
//    cv::imshow("LIST", outContours_);
//    cv::waitKey(0);
//    cv::imwrite("contours_retr_list.jpg", outContours_);
//    cv::destroyAllWindows();
//
//    //vector<vector<Point>> contours4;
//    //vector<Vec4i> hierarchy4;
//    //findContours(thresh2, contours4, hierarchy4, RETR_EXTERNAL, CHAIN_APPROX_NONE);
//    //Mat image_copy5 = image2.clone();
//    //drawContours(image_copy5, contours4, -1, Scalar(0, 255, 0), 2);
//    //imshow("EXTERNAL", image_copy5);
//    //waitKey(0);
//    //imwrite("contours_retr_external.jpg", image_copy5);
//    //destroyAllWindows();
//
//}

int main() {

    cv::VideoCapture video("C:\\Users\\Colonel\\Desktop\\Detect\\v3.mp4"); // "C:\\Users\\Colonel\\Desktop\\Detect\\v1.mp4"
    // Check that video is opened
    if (!video.isOpened()) return -1;

    // Получите разрешение видео
    int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
    int frameHeigth = video.get(cv::CAP_PROP_FRAME_HEIGHT);

    // Создать объект для записи видео
    cv::VideoWriter output("C:\\Users\\Colonel\\Desktop\\Detect\\output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeigth));


    Mat image2;// = imread("C:\\Users\\Colonel\\Desktop\\Detect\\Screenshot_1.png");
    video.read(image2);

    Mat img_gray2;
    cvtColor(image2, img_gray2, COLOR_BGR2GRAY);
    Mat thresh2;
    threshold(img_gray2, thresh2, 50, 255, THRESH_BINARY);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(thresh2, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

    // Get internal contours
    Mat outContours = img_gray2.clone();

    vector<vector<Point>> internalContours;
    for (size_t i = 0; i < contours.size(); ++i) {
        // Найдите ориентацию: CW или CC
        double area = contourArea(contours[i], true);
        if (area >= 0) {
            // Внутренний контур
            internalContours.push_back(contours[i]);

            // Рисуйте разными цветами
            drawContours(outContours, contours, i, Scalar(rand() & 255, rand() & 255, rand() & 255), 2);
        }
    }

    // Get circles 
    int ii = 0;
    Mat outContours_ = image2.clone();
    vector<Rect> a;


    for (const auto& cnt : internalContours) {
        Point2f center;
        float radius;
        minEnclosingCircle(cnt, center, radius);
        radius = ceil(radius);
        if (radius >= 20)
        {
            cout << "[" << ii << "] " << radius << endl;
            a.emplace_back( (center.x - radius), (center.y - radius), radius*2, radius*2);
            cout << a.size();
            rectangle(outContours_, a[ii], Scalar(255, 0, 0)); // boundingRect(cnt)
            circle(outContours_, center, radius, Scalar(255, 0, 0));
            ii++;
        }
    }

    // Создайте трекер, выберите интересующий регион (ROI) и инициализируйте трекер
    vector<cv::Ptr<cv::Tracker>> tracker;// = cv::TrackerCSRT::create(); //TrackerKCF
 //   vector<Mat> kadr(a.size(), image2);

    for (int i = 0; i != a.size(); i++)
    {
        tracker.emplace_back(cv::TrackerCSRT::create());
        tracker[i]->init(image2, a[i]);
    }

    // Перебор доступных фреймов
    while (video.read(image2)) {

        for (int i = 0; i < a.size(); i++)
        // Обновите трекер и нарисуйте прямоугольник вокруг цели, если обновление прошло успешно
        if (tracker[i]->update(image2, a[i])) {
            cv::rectangle(image2, a[i], cv::Scalar(255, 0, 0));
        }

        // Display the frame
        cv::imshow("Video feed", image2);

        // Write video frame to output
        output.write(image2);

        // For breaking the loop
        if (cv::waitKey(25) >= 0) break;

    } // end while (video.read(frame))

      // Release video capture and writer
    output.release();
    video.release();

    // Destroy all windows
    cv::destroyAllWindows();


}
