#include "extractLetters.h"

#define nonMarkFilePath "C:\\Users\\�۽¹�\\source\\repos\\HCI_Project\\hci-git\\HCITeam2\\HCITeam2\\testpill\\" 
//"D:\\4�г� 1�б�\\����\\KoreaPill\\nonMarkPill2\\nonMarkPillData2\\"
#define PillName (nonMarkFilePath"198901291")

int main()
{
	// �̹��� �ҷ����� 
	String imageName = PillName;
	imageName = imageName + "L.PNG";
	Mat input = imread(imageName);
	imshow("input", input);

	// BGR -> gray scale�� ����
	//cvtColor(input, input_gray, CV_BGR2GRAY);
	Mat input_gray = toGrayScale(input);
	imshow("input_gray", input_gray);

	// �̹��� ������׷� ����
	int bgcolor;
	Mat input_gray_hist = GS_imhist(bgcolor, input_gray, 300); // input_gray.size().height*input_gray.size().width
	cout << input_gray.size().height << endl;
	cout << bgcolor << endl;
	imshow("input_gray_hist", input_gray_hist);

	Mat input_gray_hist_eq = histEq(input); // GS_histeq(input_gray);
	imshow("input_gray_hist_eq", ~input_gray_hist_eq);


	// �̹��� ����ȭ
	// ��ο� �˾�, ��ο� �۾� 70
	// ���� �˾�, ���� �۾� 180
	// ���� �˾�, ��ο� �۾� 180(���� �β���) 170(����) 160(���� �����)
	// ��ο� �˾�, ���� �۾� 70
	int threshold = 170;
	Mat input_gray_threshold = getBinary(input, threshold); //GS_threshold(input_gray, threshold, THRESH_BINARY);
	imshow("input_gray_threshold", input_gray_threshold);

	Mat input_gray_hist_eq_threshold = getOTSU(input, threshold); // GS_threshold(input_gray_hist_eq, threshold, THRESH_BINARY);
	imshow("input_gray_hist_eq_threshold", input_gray_hist_eq_threshold);


	// ���� ���
	Mat input_gray_OTSU = GS_threshold(input_gray, threshold, THRESH_BINARY | THRESH_OTSU);
	imshow("input_gray_OTSU", input_gray_OTSU);

	Mat input_gray_hist_eq_OTSU = GS_threshold(input_gray_hist_eq, threshold, THRESH_BINARY | THRESH_OTSU);
	imshow("input_gray_hist_eq_OTSU", input_gray_hist_eq_OTSU);


	// linear ���ͷ� blur �̹��� ���ϰ�, gray���� �� ����, gray�� ���ؼ� ���� ����
	// ����þ� ���ͷ� blur �̹��� ���ϰ�, gray���� �� ����, gray�� ���ؼ� ���� ����
	// linear & ����þ� ���� �̿� ��, ����ġ ���ؼ� ���� �� �̱�

	// gradient sobel ���� ����
	//Mat input_gray_sobel_x;
	//// Sobel(�̺� ������ ���� �̹���, ��� �̹��� ����� ��, ��� �̹��� ������ Ÿ��, x���� �̺� ����, y���� �̺� ����)
	//Sobel(input_gray, input_gray_sobel_x, -1, 1, 0);
	//Mat input_gray_sobel_y;
	//Sobel(input_gray, input_gray_sobel_y, -1, 0, 1);
	//imshow("input_gray_sobel", input_gray_sobel_y + input_gray_sobel_y);

	// ���ö� ���ͷ� ���� ����
	//Mat input_gray_Laplacian = GS_laplacian_edge_Laplacian(input_gray); //GS_laplacian_edge_Laplacian
	//imshow("input_gray_Laplacian", input_gray_Laplacian);

	int threshold1 = 150;
	int threshold2 = 190;

	// Canny Edge detection
	Mat input_gray_canny= grayToCanny(input, threshold, threshold1, threshold2);
	// Canny(~input_gray, input_gray_canny, threshold1, threshold2);
	imshow("~input_gray", ~input_gray);
	imshow("input_gray_canny", input_gray_canny);

	Mat input_gray_threshold_canny = grayToCanny(input, threshold, threshold1, threshold2);
	// Canny(~input_gray_threshold, input_gray_threshold_canny, threshold1, threshold2);
	imshow("~input_gray_threshold", ~input_gray_threshold);
	imshow("input_gray_threshold_canny", input_gray_threshold_canny);


	// ������ ���� 
	// erode  
	// ����ȭ > canny > erode
	Mat input_gray_threshold_canny_erode;
	erode(input_gray_threshold_canny, input_gray_threshold_canny_erode, Mat());
	imshow("input_gray_threshold_canny_erode", input_gray_threshold_canny_erode);

	// ���� > erode 
	Mat input_gray_OTSU_erode;
	erode(input_gray_OTSU, input_gray_OTSU_erode, Mat());
	imshow("input_gray_OTSU_erode", input_gray_OTSU_erode);





	waitKey(0);
	return 0;
}