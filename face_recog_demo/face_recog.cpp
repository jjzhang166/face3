#include "lib_helper.h"
#include "../face/FaceRecog.h"
#include "../face/CvFrAdapter.h"

#include <iostream>
using namespace std;

void check_status(bool status, string msg) {
	if (!status) {
		cout << msg << endl;
		exit(0);
	}
}

int main(int argc, char** argv) {
	string dir_prefix = "E:/BigData/face_data/";
	FaceRecog fr;

	// ����CvFrAdapter��������ʶ��
	CvFrAdapter cvfr;
	cvfr.setFaceStorage(dir_prefix + "face_list.xml");
	fr.setFrClass(&cvfr);

	bool status = fr.train();
	check_status(status, "Train Failed...");

	// CvFrAdapter��֧�ּ��ر���Ĳ���ֱ��Ԥ�⣬����train

	int ret = fr.pridect(imread(dir_prefix + "xujian/small/9.jpg", CV_LOAD_IMAGE_GRAYSCALE));

	cout << "��������ǣ� " + fr.getNameById(ret) << endl;
	return 0;
}