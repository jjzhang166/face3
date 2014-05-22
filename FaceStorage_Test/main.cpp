#include "../face/FaceStorage.h"
#include "../face/FaceRecog.h"
#include "../face/CvFrAdapter.h"
#include "../ext/cxxlib/cv_lib.h"

#pragma comment(lib,cvLIB("core"))
#pragma comment(lib,cvLIB("contrib"))
#pragma comment(lib,cvLIB("highgui"))
//#pragma comment(lib,cvLIB("core"))

#include <iostream>
using namespace std;

int write_test() {
	FaceStorage fs;
	
	Face face;
	face.addImage("1.jpg");
	face.addImage("2.jpg");
	face.addImage("3.jpg");

	face.updata(1, "xujian");
	fs << face;

	face.updata(2, "xuzhibo");
	fs << face;

	face.updata(3, "lingyongqing");
	fs << face;

	fs.save("test.xml");
	return 0;
}
int read_test() {
	FaceStorage fs;
	fs.load("test.xml");
	cout << fs.faces.size() << endl;

	for (size_t i = 0; i < fs.size(); i++) {
		cout << "id:" << fs.faces[i].getId() << endl;
		cout << "name:" << fs.faces[i].getName() << endl;
		for (size_t j = 0; j < fs.faces[i].images.size(); j++) {
			cout << "\t" << fs.faces[i].images[j] << endl;
		}
	}
	cout << fs.getNameById(2) << endl;
	return 0;
}
void fr_test() {
	string dir = "E:/BigData/face_data/";
	FaceRecog fr; // ����ʶ����

	// ��������ʶ�����,�Լ����ø���ĳ�ʼ��
	CvFrAdapter cvfr;
	cvfr.load("face_hist.xml"); // ֱ�Ӽ���ѵ���õ���ʷ����
	fr.setFrClass(&cvfr);
	
	
	/*
	// ��ѵ������Ԥ��
	cvfr.setFaceStorage(dir+"face_list.xml");

	// ��Ȼ����ֱ�ӵ���cvfr�ĸ��ֺ�����Ϊ������չ�����Բ���������������ʽ
	

	cout << "training..." << endl;
	bool status =  fr.train();
	if (!status) {
		cout << "train failed!" << endl;
		return ;
	}
	*/
	//cvfr.save("face_hist.xml");
	cout << "load img:" << dir + "xuzhibo/small/6.jpg" << endl;
	// ʶ��
	int rt = fr.pridect(imread(dir+"xuzhibo/small/6.jpg",CV_LOAD_IMAGE_GRAYSCALE));
	// CvFrAdapter��FaceStorage��public�ģ�����ʹ�����ȡname
	cout << "������ǣ�" << fr.getNameById(rt)<<"(�����ļ�������ֱ�ӻ������),��id�ǣ�"<< rt << endl;
}


int main() {
	fr_test();
	//generate_xml_file();
	return 0;
}
