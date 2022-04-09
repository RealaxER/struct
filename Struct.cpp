// ==================== LÝ THUYẾT=================
//
// CAU1 :  Struct là gì : 
// + struct là một kiểu dữ liệu cấu trúc do người dùng tự định nghĩa tự tạo lên , bên trong nó có nhiều kiểu 
// kiểu dữ liễu khác nhau có thể được truy cập đến bằng dùng con trỏ của struct 
// 
// CAU2 : cú pháp khai báo 1 struct ?
// + để khai báo một struct ta sẽ khai ngoài hàm main giống như khai báo 1 biến toàn cục 
// + struct <ten kieu du lieu >
// {
//		<kieu du lieu 1>
//		<kieu du lieu 2>
//		<kieu du lieu 3>
// };
// 
// lúc này chúng ta có một kiểu dữ liệu là struct <......> <ten bien> ;
// 
// CAU 3 : Đặt khai báo struct dưới hàm main được không? vì sao ?
//+ theo em thì giường như là không vì ngay ở trên đã nói đây là kiểu dữ liệu biến toàn cục và đã là toàn cục thì phải trên main
// và gần các khai báo thư viện
// Và struct không có nguyên mẫu được thành ra nếu có các hàm mà cần dùng đến struct mà năm trên struct thì sẽ xảy ra lỗi;
// 
// CAU 4 : dòng typedef có chức năng gì ? tối ưu việc gì ?
// đây là dòng định nghĩa dành riêng cho struct giống như #define typedef có khả năng định nghĩa lại cách gọi của kdl struct nà
// ta đã khai báo 
// ví dụ ta có kdl : struct sinh_vien 
// ở đây để gọi thì mỗi lần gọi sẽ rất dài tốn thời gian ta có thể định nghĩa lại thành một câu sv như sau 
// typedef struct sinh_vien sv;
// 
// CAU 5:  khi nào dùng sao chép bằng toán tử gán khi nào dùng gán lần lượt ? vì sao ?
// toán tử gán là một pp rất hay để gán một biến này bằng biến kia ;
// nhưng trong vài trường hợp thì nó không phù hợp sử dụng như con trỏ hay struct 
// nếu struct có con trỏ ta sẽ phải cân nhaswsc việc dùng toán tử gán 
// nếu nó không có thì cứ gán thoải mái ( nếu có con trỏ thì thứ nó gán là miền giá trị và lúc này con trỏ ở biến có kdl struct mới 
// sẽ chung địa chỉ với biến cũ và việc gán để thay đổi sẽ mất ý nghĩa ) 
// 
// CAU 6 :  biến kdl struct có cần tham chiếu khi cập nhật giá trị thay đổi trong hàm không ?
// 
// Câu trả lời là có vì bên trong kdl struct cũng có các kiểu dữ liệu cơ bản như char , int ,string ,float 
// và từ đó nó cũng sinh ra các biến và mỗi khi thay đổi mỗi giá trị của các biến đó trong hàm thì nó vẫn hoạt động như các hàm khác 
// và muốn thay đổi ta cần tham chiếu thì mới có thể trả về giá trị thay đổi
//
// CAU 7 : . Nếu trong cấu trúc mà có biến con trỏ thì ta nên chú ý việc gì(đáp án gồm 3 ý - cố gắng trả lời đủ 3)
//  + Chú ý không dùng tóan tử gán bừa bãi trong trường hợp này vì sẽ dẫn đến TH bị chung miền giá trị 
// + Nếu có muốn copy một biến mới thì nên xây dựng hàm copy với TH ít kdl bên trong thì gán từng cái một , và con trỏ thì chỉ gán giá trị 
// chứ không gán miền giá trị ;
// + Nếu lưu giá trị vào biến con trỏ trong struct phải dùng thêm * trước dấu chỉ của cấu trúc đó;
// 
// CAU 8 : struct dễ không ?
// Quá dễ ạ , dễ nhất từ trước đến nay ;
// 
// 
// 
// 
//

#include<iostream>
using namespace std;
#include <string>
// cấu trúc thằng sinh viên
#define MAX 100 ;
struct sinh_vien
{
	char ma_sv[20] = "";
	char ho_ten[30] = " ";
	float diem_lt;
	float toan;
	float ctdl;
};
typedef struct sinh_vien sv;
// cấu trúc phân số
struct phan_so
{
	int tuSo[100];
	int mau_so[100] ;
};
typedef struct phan_so ps;
int vitri_ten(sv a[], int n);
void Rutgon_ps(ps& a, int n);
void Nhap_ps(ps& a, int n);
void Xuat_ps(ps& a, int n);
void Ps_max(ps& a, int n);
void Sum_ps(ps& a, int n);
void them_ps(ps& a, int& n, int vitri);
void xoa_ps(ps& a, int& n, int vitri);
void xuat_sv(sv a[], int n);
void Nhap_sv(sv a[], int n);
int sum_diem(sv a[], int i);
void xep_loai(sv a[], int n);

// ========================HÀM MAIN ========================================
void main()
{
	//int n = 100;
	//do
	//{
	//	cout << "\nNhap n phan so : ";
	//	cin >> n;
	//} while ((n <=0 )&&( n > 100));
	//// Khai báo và nhập xuât một cấu trúc ps;
	//ps a;Nhap_ps(a, n);Xuat_ps(a, n);
	//Ps_max(a, n);
	//Sum_ps(a, n);
	//int vitri;cout << "\n\nNhap vi tri can them : "; cin >> vitri;
	//them_ps(a, n, vitri);Xuat_ps(a, n);
	//int xoa; cout << "\n Nhap vi tri can xoa : "; cin >> xoa;
	//xoa_ps(a, n, xoa); Xuat_ps(a, n);
	//==========================SINH VIEN=======================
	int sl; 
	do
	{
		cout << "\nNhap n sinh vien : ";
		cin >> sl;
	} while ((sl <= 0) && (sl > 50));
	sv b[100]; Nhap_sv(b, sl); xuat_sv(b, sl);
	xep_loai(b, sl);
	sap_xepsv(b, sl);
	xuat_sv(b, sl);
	vitri_ten(b, sl);
	xuat_sv(b, sl);
	system("pause");
}
//=============================HÀM DƯỚI ======================
void Nhap_ps(ps &a, int n)
{
	cout << "=======================NHAP=================" << endl;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap tu so thu " << i  << " : "; cin >> a.tuSo[i];
		cout << "\nNhap mau so : " << i << " : "; cin >> a.mau_so[i];
	}
}
void Xuat_ps(ps&a, int n)
{
	cout << "===================XUAT=================" << endl;
	cout << endl;
	Rutgon_ps(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a.mau_so[i] == 1)
		{
			cout << "Phan so thu " << i << " la so : " << a.tuSo[i] << endl;
			continue;
		}
		cout << "Phan so thu " << i << " la : " << a.tuSo[i] << "/" << a.mau_so[i] << endl;
	}
}
// rút gọn ps
void Rutgon_ps(ps &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 2; j < 6; j++)
		{
			if ((a.mau_so[i] % j == 0) && (a.tuSo[i] % j == 0))
			{
				a.mau_so[i] /= j;
				a.tuSo [i]  /=  j;
			}
		}
	}
}
// Tìm phân số max;
void Ps_max(ps& a, int n)
{ 
	cout << "===============PHAN SO MAX===============" << endl;
	float ps_max = float( a.tuSo[0]) / (a.mau_so[0]);
	int kiemtra = 0;
	for (int i = 1; i < n; i++)
	{
		if ((float(a.tuSo[i]) / (a.mau_so[i])) > ps_max)
		{
			ps_max = float(a.tuSo[i]) / (a.mau_so[i]);
			kiemtra = i;
		}
	}
	cout << "\nPhan so lon nhat la : " << a.tuSo[kiemtra] << "/" << a.mau_so[kiemtra] << endl;
}
void Sum_ps(ps& a, int n)
{
	cout << "=================TONG_PHAN_SO===========" << endl;
	float total = 0;
	for (int i = 0; i < n; i++)
	{
		total = total + (float(a.tuSo[i]) / a.mau_so[i]);
	}
	cout << "\nTong phan so là : " << total << endl;
}
void them_ps(ps &a, int &n, int vitri)
{
	for (int i = n; i > vitri; i--)
	{
		a.mau_so[i] = a.mau_so[i-1];
		a.tuSo[i] = a.tuSo[i-1];
	}
	n++;
//	Xuat_ps(a, n);
	cout << "Tu so can them : "; cin >> a.tuSo[vitri];
	cout << "Mau so can them : "; cin >> a.mau_so[vitri];
}
void xoa_ps(ps& a, int& n, int vitri)
{
	for (int i = vitri; i < n; i++)
	{
		a.mau_so[i] = a.mau_so[i +1];
		a.tuSo[i] = a.tuSo[i +1];
	}
	n--;
}
/////////===============SINH VIEN===============
void Nhap_sv(sv a[], int n)
{
	for (int i = 0; i< n; i++)
	{
		cout << "=================NHAP THANG SINH VIEN THU " << i << " ================" << endl;
		cout << "Nhap ma sinh vien thang thu " << i << " : " << endl;
		cin >> a[i].ma_sv;
		cout << "Ho ten sinh vien thu " << i << " : " << endl;
		fgets(a[i].ho_ten, sizeof(a[i].ho_ten) + 1, stdin);
		cout << "Nhap diem lap trinh thang sv thu " << i << " : " << endl;
		cin >> a[i].diem_lt;
		cout << "Nhap diem toan thang sv thu " << i << " : " << endl;
		cin >> a[i].toan;
		cout << "Nhap diem ctdl thang sv thu " << i << " : " << endl;
		cin >> a[i].ctdl;
	}
}
void xuat_sv(sv a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "======= THANG SINH VIEN THU " << i << " ======= " << endl;
		cout << "\nMa sv : " << a[i].ma_sv;
		cout << "\nHo ten : " << a[i].ho_ten;
		cout << "\nDiem lap trinh : " << a[i].diem_lt;
		cout << "\nDiem toan roi rac : " << a[i].toan;
		cout << "\nDiem cau truc du lieu : " << a[i].ctdl;
		cout << endl;
	}
}
int sum_diem(sv a[], int i)
{
	float tong = a[i].diem_lt + a[i].toan + a[i].ctdl;
	tong = tong / 3;
	return tong;
}
void xep_loai(sv a[], int n)
{
	cout << "==============XEP LOAI==============";
	for (int i = 0; i < n; i++)
	{
		int diem = sum_diem(a, i);
		if (diem > 9.8)
		{
			cout << "Sinh vien thu " << i << " : Xuat sac" << endl; 
		}
		else if (diem < 9.8 && diem >= 8)
		{
			cout << "Sinh vien thu " << i << " : Gioi" << endl;
		}
		else if (diem < 8 && diem >= 6.5)
		{
			cout << "Sinh vien thu " << i << " : Kha" << endl;
		}
		else if (diem < 6.5 && diem >= 4)
		{
			cout << "Sinh vien thu " << i << " : Trung binh" << endl;
		}
		else
		{
			cout << "Sinh vien thu " << i << " : Yeu" << endl;
		}
	}
}
void sap_xepsv(sv a[], int n) // hàm sắp xếp sv theo thứ tự điểm trung bình
{
	sv temp;// khởi tạo một biến tạm 
	for (int i = 1; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sum_diem(a, i) < sum_diem(a, j))
			{
				 temp = a[i];
				 a[i] = a[j];
				 a[j] = temp;
			}
		}
	}
}
void ten_sv(sv a[], int n)
{
	cout << "=================TEN THEO BANG ASCII===========" << endl;
	char asc, asc2;
	sv temp;
	for (int i = 0; i < n-1; i++)
	{
		asc = a[i].ho_ten[vitri_ten(a,n)];
		for (int j = i + 1; j < n; j++)
		{
			asc2 = a[j].ho_ten[vitri_ten(a,n)];
			if (asc < asc2)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int vitri_ten(sv a[],int n)
{
	int dem= 0; bool kiemtra = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 31;j++)
		{
			if (a[i].ho_ten[j] == ' ')
			{
				dem++;
			}
			if (dem == 2)
			{
				return j + 1;
			}
		}
	}
}