#pragma once

#include <vector>
#include <string>

#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "../TextDetector/TextParts/Page.h"





enum DetectionMode { AUTO, MANUAL, ALL_AUTO, ALL_MANUAL };


class DocumentScanner
{

	friend class DocumentScannerGUI;

public:
	DocumentScanner();
	~DocumentScanner();
	void LoadPages(std::vector<std::string> fileNames);
	bool AreEmpty();
	cv::Mat GetSourceImageAt(int index);
	int GetNumberOfPages();
	std::vector<cv::Mat> CorrectImagePerspective(int imageIndex, DetectionMode mode);
	void PushPage(Page page);
	std::vector<cv::Mat> GetCorrectedImages();
	void Clear();


private:
	void LoadImage(std::string fileName);
	


	std::vector<cv::Mat> sourceImages;
	std::vector<Page> pages;
};

