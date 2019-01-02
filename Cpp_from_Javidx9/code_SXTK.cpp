#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double EX; // EX cua xs bnn
double VX; // VX cua xs bnn

double m_solan; double m_solan_more; // Tan so
double x_ngang; double x_ngang_more; // x_ngang
double n_SUM; double n_SUM_more; // n
double xxn_SUM; // sum(x*x*n)

double Ss_TB; double Ss_TB_more; // S^2
double Ss_PhgSai; double Ss_PhgSai_more; // S'^2
double sqrt_Ss_PhgSai; double sqrt_Ss_PhgSai_more; // S'

double PhgSai_TT; double PhgSai_TT_more; // VX_TT
double sqrt_PhgSai_TT; double sqrt_PhgSai_TT_more; // do lech chuan TT

double variable_more; double variable_more1; // U/t (theo aphal va n)
double aphal; // muc y nghia
double _aphal_plus_1; // (1-aphal) do tin cay

double KD_KUL_x; double KD_KUL_y; // cac bien trong khoang
double KD_G_qs; // G quan sat
double TB_TT_o; // Muy - EX_TT
double P_TT_o; // ti le TT


void help_case4() {
	system("cls");
	cout << "Tro Giup Xac Dinh Tham So Theo ['n' & 'aphal']." << endl;
	cout << endl;
	cout << "A. KUL cho trung binh TT:" << endl;
	cout << "	- TH biet phuong sai: DX = U(aphal/2)" << endl;
	cout << "	- TH ko biet phuong sai: DX = t(aphal/2) (n-1)" << endl;
	cout << endl;
	cout << "B. KUL cho ti le TT co PP 01:" << endl;
	cout << "	- DX = U(aphal/2)" << endl;
	cout << endl;
	cout << "C. KUL cho phuong sai TT:" << endl;
	cout << "	- TH biet Muy: DX = X^2(aphal/2)(n) ; X^2(1 - aphal/2)(n)" << endl;
	cout << "	- TH ko biet Muy: DX = X^2(aphal/2)(n-1) ; X^2(1 - aphal/2)(n-1)" << endl;
	cout << endl;
	cout << "D. KUL cho hieu 2 trung binh TT:" << endl;
	cout << "	- TH biet phuong sai: DX = U(aphal/2)" << endl;
	cout << "	- TH ko biet phuong sai (VX1 = VX2): DX = t(aphal/2) (n1 + n2 -2)" << endl;
	cout << "	- TH ko biet phuong sai: t(aphal/2) (K)" << endl;
	// cout << "            (n1 - 1) (n2 - 1)                      S1'^2 / n1           " << endl;
	// cout << "      K = ----------------------        C = --------------------------- " << endl;
	// cout << "           (1 - C^2) + C^2 * n2             (S1'^2 / n1) + (S2'^2 / n2) " << endl;
	cout << endl;
	cout << "E. KUL cho 2 ti le TT co PP 01:" << endl;
	cout << "	- DX = U(aphal/2)" << endl;
	cout << endl;
	cout << "C. KUL cho phuong sai cua 2 TT:" << endl;
	cout << "	- DX= Tich phan(1 - aphal/2)(n1-1; n2-1) ; (aphal/2)(n1-1; n2-1)" << endl;
	cout << endl;
	system("pause");
}
void del_variable() {
	EX = 0; VX = 0;
	m_solan = 0; m_solan_more = 0;
	x_ngang = 0; x_ngang_more = 0;
	n_SUM = 0; n_SUM_more = 0; xxn_SUM = 0;
	Ss_TB = 0; Ss_TB_more = 0; Ss_PhgSai = 0; Ss_PhgSai_more = 0;
	sqrt_Ss_PhgSai = 0; sqrt_Ss_PhgSai_more = 0;
	PhgSai_TT = 0; PhgSai_TT_more = 0; sqrt_PhgSai_TT = 0; sqrt_PhgSai_TT_more = 0;
	variable_more = 0; variable_more1 = 0;
	aphal = 0; _aphal_plus_1 = 0;
	KD_KUL_x = 0; KD_KUL_y = 0;
	KD_G_qs = 0;
	TB_TT_o = 0;
	P_TT_o = 0;
}
// get variable fuctions
double get_aphal() {
	double a = 0;
	if (aphal != 0) { a = aphal; }
	else if ((aphal == 0) && (_aphal_plus_1 != 0)) {
		a = 1 - (_aphal_plus_1 / 100);
	}
	return a;
}
double get_PhgSai_TT() {
	double a = 0;
	if (PhgSai_TT != 0) {
		a = PhgSai_TT;
	}
	else if (PhgSai_TT == 0 && sqrt_PhgSai_TT != 0) {
		a = pow(sqrt_PhgSai_TT, 2);
	}
	return a;
}
double get_sqrt_PhgSai_TT() {
	double a = 0;
	if (sqrt_PhgSai_TT != 0) {
		a = sqrt_PhgSai_TT;
	}
	else if (sqrt_PhgSai_TT == 0 && PhgSai_TT != 0) {
		a = sqrt(PhgSai_TT);
	}
	return a;
}
double get_PhgSai_TT_more() {
	double a = 0;
	if (PhgSai_TT_more != 0) {
		a = PhgSai_TT_more;
	}
	else if (PhgSai_TT_more == 0 && sqrt_PhgSai_TT_more != 0) {
		a = pow(sqrt_PhgSai_TT_more, 2);
	}
	return a;
}
double get_sqrt_PhgSai_TT_more() {
	double a = 0;
	if (sqrt_PhgSai_TT_more != 0) {
		a = sqrt_PhgSai_TT_more;
	}
	else if (sqrt_PhgSai_TT_more == 0 && PhgSai_TT_more != 0) {
		a = sqrt(PhgSai_TT_more);
	}
	return a;
}
double get_Ss_PhgSai() {
	double a = 0;
	if (Ss_PhgSai != 0) {
		a = Ss_PhgSai;
	}
	else {
		if (Ss_PhgSai == 0 && sqrt_Ss_PhgSai != 0) {
			a = pow(sqrt_Ss_PhgSai, 2);
		}
		else {
			if (Ss_PhgSai == 0 && sqrt_Ss_PhgSai == 0 && Ss_TB != 0) {
				a = (n_SUM / (n_SUM - 1)) * Ss_TB;
			}
		}
	}
	return a;
}
double get_sqrt_Ss_PhgSai() {
	double a = 0;
	if (sqrt_Ss_PhgSai != 0) {
		a = sqrt_Ss_PhgSai;
	}
	else {
		if (sqrt_Ss_PhgSai == 0 && Ss_PhgSai != 0) {
			a = sqrt(Ss_PhgSai);
		}
		else {
			if (sqrt_Ss_PhgSai == 0 && Ss_PhgSai == 0 && Ss_TB != 0) {
				a = sqrt((n_SUM / (n_SUM - 1)) * Ss_TB);
			}
		}
	}
	return a;
}
double get_Ss_PhgSai_more() {
	double a = 0;
	if (Ss_PhgSai_more != 0) {
		a = Ss_PhgSai_more;
	}
	else {
		if (Ss_PhgSai_more == 0 && sqrt_Ss_PhgSai_more != 0) {
			a = pow(sqrt_Ss_PhgSai_more, 2);
		}
		else {
			if (Ss_PhgSai_more == 0 && sqrt_Ss_PhgSai_more == 0 && Ss_TB_more != 0) {
				a = (n_SUM_more / (n_SUM_more - 1)) * Ss_TB_more;
			}
		}
	}
	return a;
}
double get_sqrt_Ss_PhgSai_more() {
	double a = 0;
	if (sqrt_Ss_PhgSai_more != 0) {
		a = sqrt_Ss_PhgSai_more;
	}
	else {
		if (sqrt_Ss_PhgSai_more == 0 && Ss_PhgSai_more != 0) {
			a = sqrt(Ss_PhgSai_more);
		}
		else {
			if (sqrt_Ss_PhgSai_more == 0 && Ss_PhgSai_more == 0 && Ss_TB_more != 0) {
				a = sqrt((n_SUM_more / (n_SUM_more - 1)) * Ss_TB_more);
			}
		}
	}
	return a;
}



struct bienco {
	double X;
	double P;

}; bienco A[100];

class bangpp {
	int n;
public:
	bangpp() { del_variable(); }
	~bangpp() {}

	// (check if)...
	double checkP() {
		double tongP = 0;
		for (int i = 0; i<n; i++) {
			tongP = tongP + A[i].P;
		}
		return tongP;
	} // kiểm tra tổng P=1...
	int checkX() {
		int a = 1; int x = 1;
		for (int i = 0; i<n - 1; i++) {
			if (A[i].X < A[i + 1].X) { a = 1; }
			else { a = 0; }
			x = x * a;
		}
		return x;
	} // kiểm tra G/t X phải theo thứ tự...
	int checkP_0() {
		int x = 1;
		for (int i = 0; i<n; i++) {
			if (0 > A[i].P) { x = 0; break; }
		}
		return x;
	} //kiểm tra XS P luôn >= 0..

	void nhap_BPP_none_KUL() {
		del_variable(); system("cls");
		cout << "Nhap vao cac gia tri duoi day:" << endl;
		cout << "note: typing '0' if you don't know that" << endl;
		cout << ">_  m [So lan xh b/c 1]    = "; cin >> m_solan;
		cout << ">_  m [So lan xh b/c 2]    = "; cin >> m_solan_more;
		cout << ">_  n [co mau 1]           = "; cin >> n_SUM;
		cout << ">_  n [co mau 2]           = "; cin >> n_SUM_more;
		cout << ">_  x [TB mau 1]           = "; cin >> x_ngang;
		cout << ">_  x [TB mau 2]           = "; cin >> x_ngang_more;
		cout << ">_  Mo [TB TT]             = "; cin >> TB_TT_o;
		cout << ">_  Po [Ti le TT]          = "; cin >> P_TT_o;
		cout << ">_  O^2 [Phg Sai TT 1]     = "; cin >> PhgSai_TT;
		cout << ">_  O^2 [Phg Sai TT 2]     = "; cin >> PhgSai_TT_more;
		cout << ">_  O [Do lech chuan 1]    = "; cin >> sqrt_PhgSai_TT;
		cout << ">_  O [Do lech chuan 2]    = "; cin >> sqrt_PhgSai_TT_more;
		cout << ">_  S^2 [TB Phg Sai mau 1] = "; cin >> Ss_TB;
		cout << ">_  S^2 [TB Phg Sai mau 2] = "; cin >> Ss_TB_more;
		cout << ">_  S'^2 [Phg Sai mau 1]   = "; cin >> Ss_PhgSai;
		cout << ">_  S'^2 [Phg Sai mau 2]   = "; cin >> Ss_PhgSai_more;
		cout << ">_  S' [Do lech chuan 1]   = "; cin >> sqrt_Ss_PhgSai;
		cout << ">_  S' [Do lech chuan 2]   = "; cin >> sqrt_Ss_PhgSai_more;
		cout << ">_  (1 - aphal)            = "; cin >> _aphal_plus_1;
		cout << ">_  aphal                  = "; cin >> aphal;
		cout << ">_  Tham So 1 [aphal & n]  = "; cin >> variable_more;
		cout << ">_  Tham So 2 <neu co>     = "; cin >> variable_more1;
		cout << "=======================================" << endl;
		cout << "a    = " << get_aphal() << endl;
		cout << "S'^2 = " << get_Ss_PhgSai() << endl;
		cout << "S'   = " << get_sqrt_Ss_PhgSai() << endl;
		cout << "O^2  = " << get_PhgSai_TT() << endl;
		cout << "O    = " << get_sqrt_PhgSai_TT() << endl;

		system("pause");
	} // input without BPP
	void nhap_BPP() {
		system("cls");
		n = 0;
		cout << "\n===============================\n";
		cout << " Nhap vao n lan: "; cin >> n;
		for (int i = 0; i<n; i++) {
			cout << i + 1 << "____________________" << endl;
			cout << "- Nhap vao X/x: "; cin >> A[i].X;
			cout << "- Nhap vao P/n: "; cin >> A[i].P;
		}
	} // input
	void xuat_BPP() {
		system("cls");
		cout << " Bang PP XS bien ngau nhien cua X" << endl;
		for (int i = 0; i<n; i++) {
			cout << "-> | " << A[i].X << " / " << A[i].P << endl;
		}
	} // display
	void xuat_KD_KUL_DX(double x, double y) {
		cout << "Khoang UL DX bang:" << endl;
		cout << "==================" << endl;
		cout << ">_  ( " << x << " , " << y << " )" << endl;
	} // tim khoang Doi Xung
	void xuat_KD_KUL_left(double y) {
		cout << "Khoang UL trai bang:" << endl;
		cout << "====================" << endl;
		cout << ">_  ( -oo , " << y << " )" << endl;
	} // tim max
	void xuat_KD_KUL_right(double x) {
		cout << "Khoang UL phai bang:" << endl;
		cout << "====================" << endl;
		cout << ">_  ( " << x << " , +oo )" << endl;
	} // tim min
	void delall() {
		for (int i = 0; i<n; i++) {
			A[i].X = 0; A[i].P = 0;
		}
	} // Del...

	  // caculation...
	  // case 1:
	double PX(int i) {
		double a;
		a = A[i].X * A[i].P;
		return a;
	} // P*X..
	double PXX(int i) {
		double a;
		a = A[i].X * A[i].X * A[i].P;
		return a;
	} // P*X*X..
	double get_EX() {
		double a = 0;
		for (int j = 0; j<n; j++) {
			a += PX(j);
		}
		return a;
	}
	double get_VX() {
		double a; double PXX_SUM = 0;
		for (int i = 0; i<n; i++) {
			PXX_SUM += PXX(i);
		}
		a = PXX_SUM - (EX*EX);
		return a;
	}

	// case 2->4:
	double n_SUM_def() {
		double a = 0;
		for (int j = 0; j < n; j++) {
			a += A[j].P;
		}
		return a;
	}
	double x_ngang_def() {
		double a;
		a = get_EX() / n_SUM_def();
		return a;
	}
	double xxn_SUM_def() {
		double a = 0;
		for (int j = 0; j < n; j++) {
			a += PXX(j);
		}
		return a;
	}
	double Ss_TB_def() {
		double a;
		a = (xxn_SUM_def() / n_SUM_def()) - pow(x_ngang_def(), 2);
		return a;
	}
	double Ss_PhgSai_def() {
		double a;
		a = (n_SUM_def() / (n_SUM_def() - 1)) * Ss_TB_def();
		return a;
	}
	double TB_TT_def() {
		double a;
		a = x_ngang_def();
		return a;
	}
	double PhgSai_TT_def() {
		double a;
		a = Ss_TB_def();
		return a;
	}
	double get_f_TanXuat_1() {
		double a;
		a = m_solan / n_SUM;
		return a;
	}
	double get_f_TanXuat_2() {
		double a;
		a = m_solan_more / n_SUM_more;
		return a;
	}
	double variable_unknow1(int j) {
		double a;
		a = A[j].X * TB_TT_o;
		return a;
	}
	double SUM_unknow1() {
		double a = 0;
		for (int i = 0; i < n; i++) {
			a += variable_unknow1(i);
		}
		return pow(a, 2);
	}

	// case 2->5:
	// 	CT_Khoang Uoc Luong:
	//	KUL cho TB 1 Tong The
	//		TH1: Khi biet PhgSai_TT
	double M1_x_O() {
		KD_KUL_x = 0;
		KD_KUL_x = x_ngang - (get_PhgSai_TT() / sqrt(n_SUM)) * variable_more;
		return KD_KUL_x;
	}
	double M1_y_O() {
		KD_KUL_y = 0;
		KD_KUL_y = x_ngang + (get_PhgSai_TT() / sqrt(n_SUM)) * variable_more;
		return KD_KUL_y;
	}
	//		TH2: Khi chua biet VX
	double M1_x_none() {
		KD_KUL_x = 0;
		KD_KUL_x = x_ngang - (get_sqrt_Ss_PhgSai() / sqrt(n_SUM)) * variable_more;
		return KD_KUL_x;
	}
	double M1_y_none() {
		KD_KUL_y = 0;
		KD_KUL_y = x_ngang + (get_sqrt_Ss_PhgSai() / sqrt(n_SUM)) * variable_more;
		return KD_KUL_y;
	}
	//	KUL cho hieu TB 2 Tong The
	//		TH1: Khi biet PhgSai_TT "VX"
	double M2_x_O() {
		KD_KUL_x = 0;
		KD_KUL_x = x_ngang - x_ngang_more - (sqrt((get_PhgSai_TT() / n_SUM) + (get_PhgSai_TT_more() / n_SUM_more)) * variable_more);
		return KD_KUL_x;
	}
	double M2_y_O() {
		KD_KUL_y = 0;
		KD_KUL_y = x_ngang - x_ngang_more + (sqrt((get_PhgSai_TT() / n_SUM) + (get_PhgSai_TT_more() / n_SUM_more)) * variable_more);
		return KD_KUL_y;
	}
	//		TH2: Khi ko biet PhgSai_TT (gia dinh: VX1 = VX2)
	double M2_x_gd() {
		KD_KUL_x = 0;
		KD_KUL_x = x_ngang - x_ngang_more - (sqrt((((n_SUM - 1) * get_Ss_PhgSai()) + ((n_SUM_more - 1) * get_Ss_PhgSai_more())) / (n_SUM + n_SUM_more - 2)) * sqrt((1 / n_SUM) + (1 / n_SUM_more)) * variable_more);
		return KD_KUL_x;
	}
	double M2_y_gd() {
		KD_KUL_y = 0;
		KD_KUL_y = x_ngang - x_ngang_more + (sqrt((((n_SUM - 1) * get_Ss_PhgSai()) + ((n_SUM_more - 1) * get_Ss_PhgSai_more())) / (n_SUM + n_SUM_more - 2)) * sqrt((1 / n_SUM) + (1 / n_SUM_more)) * variable_more);
		return KD_KUL_y;
	}
	//		TH3: Khi ko biet PhgSai_TT (ko duoc gia dinh)
	double M2_x_none() {
		KD_KUL_x = 0;
		KD_KUL_x = x_ngang - x_ngang_more - sqrt((get_Ss_PhgSai() / n_SUM) + (get_Ss_PhgSai_more() / n_SUM_more)) * variable_more;
		return KD_KUL_x;
	}
	double M2_y_none() {
		KD_KUL_y = 0;
		KD_KUL_y = x_ngang - x_ngang_more + sqrt((get_Ss_PhgSai() / n_SUM) + (get_Ss_PhgSai_more() / n_SUM_more)) * variable_more;
		return KD_KUL_y;
	}
	//	KUL cho ti le Tong The theo PP 0-1
	double P1_x_none() {
		KD_KUL_x = 0;
		KD_KUL_x = get_f_TanXuat_1() - sqrt((get_f_TanXuat_1() * (1 - get_f_TanXuat_1())) / n_SUM) * variable_more;
		return KD_KUL_x;
	}
	double P1_y_none() {
		KD_KUL_y = 0;
		KD_KUL_y = get_f_TanXuat_1() + sqrt((get_f_TanXuat_1() * (1 - get_f_TanXuat_1())) / n_SUM) * variable_more;
		return KD_KUL_y;
	}
	//	KUL cho hieu 2 ti le Tong The theo PP 0-1
	double P2_x_none() {
		KD_KUL_x = get_f_TanXuat_1() - get_f_TanXuat_2() - sqrt(((get_f_TanXuat_1() * (1 - get_f_TanXuat_1())) / n_SUM) + (get_f_TanXuat_2() * (1 - get_f_TanXuat_2())) / n_SUM_more) * variable_more;
		return KD_KUL_x;
	}
	double P2_y_none() {
		KD_KUL_y = 0;
		KD_KUL_y = get_f_TanXuat_1() - get_f_TanXuat_2() + sqrt(((get_f_TanXuat_1() * (1 - get_f_TanXuat_1())) / n_SUM) + (get_f_TanXuat_2() * (1 - get_f_TanXuat_2())) / n_SUM_more) * variable_more;
		return KD_KUL_y;
	}
	//	KUL cho phuong sai TT
	//		TH1: Khi biet TB_TT (Muy)
	double O1_x_M() {
		KD_KUL_x = 0;
		KD_KUL_x = SUM_unknow1() / variable_more;
		return KD_KUL_x;
	}
	double O1_y_M() {
		KD_KUL_y = 0;
		KD_KUL_y = SUM_unknow1() / variable_more1;
		return KD_KUL_y;
	}
	//		TH2: Khi ko biet TB_TT
	double O1_x_none() {
		KD_KUL_x = 0;
		KD_KUL_x = ((n_SUM - 1) * get_Ss_PhgSai()) / variable_more;
		return KD_KUL_x;
	}
	double O1_y_none() {
		KD_KUL_y = 0;
		KD_KUL_y = ((n_SUM - 1) * get_Ss_PhgSai()) / variable_more1;
		return KD_KUL_y;
	}
	//	KUL cho ti le 2 phuong sai Tong The
	double O2_x_none() {
		KD_KUL_x = 0;
		KD_KUL_x = (get_Ss_PhgSai() / get_Ss_PhgSai_more()) * variable_more;
		return KD_KUL_x;
	}
	double O2_y_none() {
		KD_KUL_y = 0;
		KD_KUL_y = (get_Ss_PhgSai() / get_Ss_PhgSai_more()) * variable_more1;
		return KD_KUL_y;
	}

	// 	CT_G.qs - Kiem Dinh
	//	KD cho Muy
	//		TH: biet TB_TT
	double KD_M1_O() {
		double a;
		a = ((x_ngang - TB_TT_o) / get_sqrt_PhgSai_TT()) * sqrt(n_SUM);
		return a;
	}
	//		TH: ko biet TB_TT
	double KD_M1_none() {
		double a;
		a = ((x_ngang - TB_TT_o) / get_sqrt_Ss_PhgSai()) * sqrt(n_SUM);
		return a;
	}
	//	KD cho P
	double KD_P1_none() {
		double a;
		a = ((get_f_TanXuat_1() - P_TT_o) / sqrt(P_TT_o * (1 - P_TT_o))) * sqrt(n_SUM);
		return a;
	}
	//	KD cho Phg sai
	double KD_O1_none() {
		double a;
		a = ((n_SUM - 1) * get_Ss_PhgSai()) / get_PhgSai_TT();
		return a;
	}
	//	KD cho 2 Muy
	//		TH: biet TB_TT
	double KD_M2_O() {
		double a;
		a = (x_ngang - x_ngang_more - TB_TT_o) / sqrt((get_PhgSai_TT() / n_SUM) + (get_PhgSai_TT_more() / n_SUM));
		return a;
	}
	// 		TH: ko biet TB_TT
	double KD_M2_none() {
		double a;
		a = (x_ngang - x_ngang_more - TB_TT_o) / sqrt((get_Ss_PhgSai() / n_SUM) + (get_Ss_PhgSai_more() / n_SUM));
		return a; }
	//		TH: ko biet TB_TT, co gd, n<30
	double KD_M2_gd() {
		double a;
		a = (x_ngang - x_ngang_more - TB_TT_o) / (sqrt((((n_SUM - 1) * get_Ss_PhgSai()) + ((n_SUM_more - 1) * get_Ss_PhgSai_more())) / (n_SUM + n_SUM_more - 2)) * sqrt((1 / n_SUM) + (1 / n_SUM_more)));
		return a;
	}
	//		TH: ko biet TB_TT, n<30
	double KD_M2_gd_none() {
		double a;
		a = (x_ngang - x_ngang_more - TB_TT_o) / ((pow((get_Ss_PhgSai()/n_SUM + get_Ss_PhgSai_more()/n_SUM_more),2) / (pow((get_Ss_PhgSai()/n_SUM),2) / (n_SUM-1) + pow((get_Ss_PhgSai_more()/n_SUM_more),2) / (n_SUM_more-1)))  * sqrt((1 / n_SUM) + (1 / n_SUM_more)));
		return a;
	}
	//	KD cho 2 P
	double KD_P2_none() {
		double a;
		a = (get_f_TanXuat_1()-get_f_TanXuat_2()-P_TT_o) / sqrt(((n_SUM*get_f_TanXuat_1()+n_SUM_more*get_f_TanXuat_2())/(n_SUM+n_SUM_more)) * (1-((n_SUM*get_f_TanXuat_1()+n_SUM_more*get_f_TanXuat_2())/(n_SUM+n_SUM_more))) * ((1/n_SUM)+(1/n_SUM_more)));
		return a; }
	// 	KD cho 2 Phg sai
	double KD_O2_none() {
		double a;
		if (get_Ss_PhgSai() >= get_Ss_PhgSai_more()) {a = get_Ss_PhgSai() / get_Ss_PhgSai_more();}
		else {a = get_Ss_PhgSai_more() / get_Ss_PhgSai();}
		return a;
	}

}; bangpp B;



// Menu
int menu() {
	system("cls");
	int m;
	cout << "Select your solution down here:" << endl;
	cout << "0. Thoat khoi chuong trinh." << endl;
	cout << "1. Tinh cac dac trung Ql PP-XS cua bien ngau nhien." << endl;
	cout << "2. Tinh cac dac trung cua tong the." << endl;
	cout << "3. Tinh cac dac trung cua mau." << endl;
	cout << "4. Tinh khoang uoc luong." << endl;
	cout << "5. Kiem dinh (tinh G)." << endl; // G result
	cout << "=========" << endl;
	cout << ">>> ";
	cin >> m;
	return m;
}
int menu_case_4() {
	system("cls");
	int m;
	cout << "Ban muon Uoc Luong cho:" << endl;
	cout << "0. Thoat." << endl;
	cout << "1. Uoc luong cho 1 hoac 2 TB tong the co phan phoi chuan." << endl;
	cout << "2. Uoc luong cho 1 hoac 2 ti le tong the co phan phoi 0-1." << endl;
	cout << "3. Uoc luong cho 1 hoac 2 phuong sai cua tong the co phan phoi chuan." << endl;
	cout << "=========" << endl;
	cout << ">>> ";
	cin >> m;
	cout << endl;
	return m;
}
int menu_case_5() {
	system("cls");
	int m;
	cout << "Ban muon Kiem Dinh cho:" << endl;
	cout << "0. Thoat." << endl;
	cout << "1. KD cho Trung Binh cua Tong The co PP chuan." << endl;
	cout << "2. KD cho Ti Le cua Tong The co PP chuan." << endl;
	// cout << "3. KD cho Phuong Sai cua Tong The co PP chuan." << endl;
	cout << "4. KD cho 2 Trung Binh cua Tong The co PP chuan." << endl;
	// cout << "5. KD cho 2 Ti Le cua Tong The co PP chuan." << endl;
	// cout << "6. KD cho 2 Phuong Sai cua Tong The co PP chuan." << endl;
	cout << "=========" << endl;
	cout << ">>> ";
	cin >> m;
	cout << endl;
	return m;
}

// choose frame
int return_choose_123_KUL() {
	int a;
	cout << "Ban muon tinh trong khoang nao ['1 = DX' or '2 = L' or '3 = R']: ";
	cin >> a;
	return a;
}
void choose_frame_KUL123_function(double x, double y) {
	cout << "\nKet Qua:" << endl;
	cout << "==========" << endl;
	int a = return_choose_123_KUL();
	if (a == 1) { B.xuat_KD_KUL_DX(x, y); }
	else if (a == 2) { B.xuat_KD_KUL_left(y); }
	else if (a == 3) { B.xuat_KD_KUL_right(x); }
	system("pause");
}
void choose_frame_KD_function(double x) {
	cout << "\nKet Qua:" << endl;
	cout << "G quan-sat = " << x << endl;
	system("pause");
}

// kind of KQ_BPP
void BPP_bnn() {
	B.xuat_BPP();
	cout << "\n> Voi Bang PP-XS tren Ta co:" << endl;
	cout << "=============================" << endl;
	cout << "> EX [KyVongToan]  = " << B.get_EX() << endl;
	cout << "> VX [PhuongSai]   = " << B.get_VX() << endl;
	cout << "> O  [DoLechChuan] = " << sqrt(B.get_VX()) << endl;
}
void BPP_TT() {
	B.xuat_BPP();
	cout << "\n> Voi Bang PP-XS tren Ta co:" << endl;
	cout << "=============================" << endl;
	cout << "> EX [TB-TT] = " << B.TB_TT_def() << endl;
	cout << "> VX [PS-TT] = " << B.PhgSai_TT_def() << endl;
	cout << "> O  [DLC]   = " << sqrt(B.PhgSai_TT_def()) << endl;
}
void BPP_m() {
	B.xuat_BPP();
	cout << "\n> Voi Bang PP-XS tren Ta co:" << endl;
	cout << "=============================" << endl;
	cout << "> X-ng [TBmau]  = " << B.x_ngang_def() << endl;
	cout << "> S^2  [TB_PS]  = " << B.Ss_TB_def() << endl;
	cout << "> S'^2 [PhgSai] = " << B.Ss_PhgSai_def() << endl;
	cout << "> S'   [DLC]    = " << sqrt(B.Ss_PhgSai_def()) << endl;
}



// Tinh bang phan phoi xac suat bien ngau nhien
void case1() {
	char choose;
	do {
		B.nhap_BPP(); // input case 1

		if (B.checkP_0() == 1) {
			if (B.checkX() == 1) {
				if (B.checkP() == 1) {
					BPP_bnn();
				}
				else { B.xuat_BPP(); cout << "\nLoi: Tong cac XS P khong bang 1." << endl; cout << "-> Moi ban nhap lai!" << endl; }
			}
			else { B.xuat_BPP(); cout << "\nLoi: Gia tri X ko theo thu tu hoac trung lap." << endl; cout << "-> Moi ban nhap lai!" << endl; }
		}
		else { B.xuat_BPP(); cout << "\nLoi: Xac suat P duoc nhap nho hon 0." << endl; cout << "-> Moi ban nhap lai!" << endl; }

		// choose what your choice [yes / no] to break from while function
		cout << "\nDo you want to break (y/n): "; cin >> choose;
		choose = toupper(choose);
		if (choose == 'Y') { B.delall(); break; }

	} while (1);
}
// Tinh bang phan phoi xac suat cua tong the
void case2() {
	char choose;
	do {
		B.nhap_BPP();
		BPP_TT();
		cout << "\nDo you want to break (y/n): "; cin >> choose;
		choose = toupper(choose);
		if (choose == 'Y') { B.delall(); break; }

	} while (1);
}
// Tinh bang phan phoi xac suat cua mau
void case3() {
	char choose;
	do {
		B.nhap_BPP();
		BPP_m();
		cout << "\nDo you want to break (y/n): "; cin >> choose;
		choose = toupper(choose);
		if (choose == 'Y') { B.delall(); break; }

	} while (1);
}

// KUL function
void case4_1() { // cho TB TT
	int choose;
	if ((n_SUM_more == 0) && (x_ngang_more == 0)) { // KUL cho TB TT
		if (get_PhgSai_TT() != 0) {
			cout << "KUL cho TB TT TH1: biet VX_TT" << endl;
			choose_frame_KUL123_function(B.M1_x_O(), B.M1_y_O());
		}
		else if (get_PhgSai_TT() == 0) {
			cout << "KUL cho TB TT TH2: ko biet VX_TT" << endl;
			choose_frame_KUL123_function(B.M1_x_none(), B.M1_y_none());
			/*choose_KUL = return_choose_123_KUL();
			if (choose_KUL == 1) {
			B.xuat_KD_KUL_DX(B.M1_x_none(), B.M1_y_none());
			}
			else {
			if (choose_KUL == 2) {
			B.xuat_KD_KUL_left(B.M1_y_none());
			}
			else {
			if (choose_KUL == 3) {
			B.xuat_KD_KUL_right(B.M1_x_none());
			}
			}
			}*/
		}
	}
	else if ((n_SUM_more != 0) && (x_ngang_more != 0)) { // KUL cho hieu TB 2 TT
		if (get_PhgSai_TT() != 0 && get_PhgSai_TT_more() != 0) {
			cout << "KUL cho hieu TB 2 TT TH1: biet VX_TT" << endl;
			choose_frame_KUL123_function(B.M2_x_O(), B.M2_y_O());
		}
		else if (get_PhgSai_TT() == 0 && get_PhgSai_TT_more() == 0) {
			choose = 0;
			cout << "KUL cho hieu 2 TB TT trong TH: chua biet VX.";
			cout << "Ban co muon dua ra gia thiet VX1 = VX2 hay ko ('0 = ko' / '1 = co'): ";
			cin >> choose;

			if (choose == 1) {
				cout << "KUL cho hieu TB 2 TT TH2: ko biet VX_TT nhung co gia dinh VX_TT1 = VX_TT2" << endl;
				choose_frame_KUL123_function(B.M2_x_gd(), B.M2_y_gd());
			}
			else if (choose == 0) {
				cout << "KUL cho hieu TB 2 TT TH3: ko biet VX_TT va ko co gia dinh nao" << endl;
				choose_frame_KUL123_function(B.M2_x_none(), B.M2_y_none());
			}
		}
	}
}
void case4_2() { // cho ti le TT
	if (n_SUM_more == 0) {
		cout << "KUL cho ti le TT co PP chuan 0-1" << endl;
		choose_frame_KUL123_function(B.P1_x_none(), B.P1_y_none());
	}
	else if (n_SUM_more != 0) {
		cout << "KUL cho hieu 2 ti le TT co PP chuan 0-1" << endl;
		choose_frame_KUL123_function(B.P2_x_none(), B.P2_y_none());
	}
}
void case4_3() { // cho ti le phuong sai
	if (n_SUM_more == 0) {
		if (TB_TT_o != 0) {
			cout << "KUL cho phuong sai TT TH1: Khi da biet Muy" << endl;
			cout << "Ban can phai nhap vao BPP sau:" << endl;
			cout << "note: gia tri P/n co the bo qua." << endl;
			B.nhap_BPP();
			choose_frame_KUL123_function(B.O1_x_M(), B.O1_y_M());
			B.delall();
		}
		else if (TB_TT_o == 0) {
			cout << "KUL cho phuong sai TT TH2: Khi chua biet Muy" << endl;
			choose_frame_KUL123_function(B.O1_x_none(), B.O1_y_none());
		}
	}
	else if (n_SUM_more != 0) {
		cout << "KUL cho phuong sai 2 Tong The" << endl;
		choose_frame_KUL123_function(B.O2_x_none(), B.O2_y_none());
	}
}
// Tinh khoang uoc luong
void case4() {
	int menu_selected_item_case_4; int count = 0;
	do {
		help_case4();
		B.nhap_BPP_none_KUL();
		menu_selected_item_case_4 = menu_case_4();
		switch (menu_selected_item_case_4) {
		case 1: case4_1(); break;
		case 2: case4_2(); break;
		case 3: case4_3(); break;
		default: break;
		}
		count++;
	} while (count == 0 && menu_selected_item_case_4 != 0);
}

// KD function
void case5_1() {
	if (get_PhgSai_TT() != 0) {
		cout << "KD cho Muy TH: biet PhgSai" << endl;
		choose_frame_KD_function(B.KD_M1_O());
	}
	else if (get_Ss_PhgSai() != 0) {
		cout << "KD cho Muy TH: ko biet PhgSai" << endl;
		choose_frame_KD_function(B.KD_M1_none());
	}
}
void case5_2() {
	cout << "KD cho ti le (P)" << endl;
	choose_frame_KD_function(B.KD_P1_none());
}
void case5_3() {
	cout << "\nKD cho phuong sai TT" << endl;
	cout << "Ket Qua: X^2 = " << B.KD_O1_none() << endl;
	system("pause");
}
void case5_4() {
	int choose;
	if (get_PhgSai_TT() != 0) {
		cout << "KD cho 2 Muy TH: biet PhgSai" << endl;
		choose_frame_KD_function(B.KD_M2_O());
	}
	else if (get_Ss_PhgSai() != 0) {
		if (n_SUM>=30 && n_SUM_more>=30) {
			cout << "KD cho 2 Muy TH: ko biet PhgSai va n1,n2 >= 30" << endl;
			choose_frame_KD_function(B.KD_M2_none());
		}
		else{
			choose = 0;
			cout << "Ban co muon dua ra gia thiet VX1 = VX2 hay ko ('0 = ko' / '1 = co'): ";
			cin >> choose;

			if (choose == 1) {
				cout << "KD cho 2 Muy TH: ko biet PhgSai, gd: (VX_TT1 = VX_TT2)" << endl;
				choose_frame_KD_function(B.KD_M2_gd());
			}
			else if (choose == 0) {
				cout << "KD cho 2 Muy TH: ko biet PhgSai" << endl;
				choose_frame_KD_function(B.KD_M2_gd_none());
			}
		}
	}
}
void case5_5() {
	cout << "KD cho 2 ti le (P)" << endl;
	choose_frame_KD_function(B.KD_P2_none());
}
void case5_6() {
	cout << "\nKD cho phuong sai 2 TT" << endl;
	cout << "Ket Qua: F = " << B.KD_O2_none() << endl;
	system("pause");
}
// Kiem dinh
void case5() {
	int menu_selected_item_case_5; int count = 0;
	do {
		B.nhap_BPP_none_KUL();
		menu_selected_item_case_5 = menu_case_5();
		switch (menu_selected_item_case_5) {
		case 1: case5_1(); break;
		case 2: case5_2(); break;
		case 3: case5_3(); break;
		case 4: case5_4(); break;
		case 5: case5_5(); break;
		case 6: case5_6(); break;
		default: break;
		}
		count++;

	} while (count == 0 && menu_selected_item_case_5 != 0);
}



// main function
int main() {
	int menu_selected_item;
	do {
		menu_selected_item = menu();
		switch (menu_selected_item) {
		case 1: case1(); break;
		case 2: case2(); break;
		case 3: case3(); break;
		case 4: case4(); break;
		case 5: case5(); break;
		default: break;
		}

	} while (menu_selected_item != 0);

	system("pause");
	return 0;
}
