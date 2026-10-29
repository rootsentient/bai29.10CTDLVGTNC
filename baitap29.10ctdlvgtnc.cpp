
#include <iostream>
#include <string>
using namespace std;

// Cau 1: Khai bao cau truc hang hoa
struct HangHoa {
    string ma, ten;
    int ngay, thang, nam;
    float gia;
};

// Cau 2: Nhap danh sach hang hoa
void nhap(HangHoa a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap hang hoa thu " << i + 1 << ":\n";

        cout << "Ma hang: ";
        cin >> a[i].ma;

        cout << "Ten hang: ";
        cin.ignore();
        getline(cin, a[i].ten);
  
        cout << "Ngay thang nam xuat hang: ";
        cin >> a[i].ngay >> a[i].thang >> a[i].nam;

        cout << "Gia xuat (trieu dong): ";
        cin >> a[i].gia;
    }
}

// Cau 3: Xuat danh sach hang hoa
void xuat(HangHoa a[], int n) {
    cout << "\nMa\tTen\tNgay xuat\tGia\n";
    for (int i = 0; i < n; i++) {
        cout << a[i].ma << "\t"
             << a[i].ten << "\t"
             << a[i].ngay << "/"
             << a[i].thang << "/"
             << a[i].nam << "\t"
             << a[i].gia << endl;
    }
}


// Ham doi cho hai hang hoa
void doiCho(HangHoa &a, HangHoa &b) {
    HangHoa temp = a;
    a = b;
    b = temp;
}

// Cau 4: Sap xep nhanh Quick Sort
void quickSort(HangHoa a[], int left, int right) {
    int i = left, j = right;
    float chot = a[(left + right) / 2].gia;

    while (i <= j) {
        while (a[i].gia < chot)
            i++;

        while (a[j].gia > chot)
            j--;

        if (i <= j) {
            doiCho(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(a, left, j);

    if (i < right)
        quickSort(a, i, right);
}

// Cau 5: Tim kiem nhi phan
void timKiem(HangHoa a[], int n, float X) {
    int left = 0, right = n - 1;
    bool timThay = false;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid].gia == X) {
            // In hang hoa tim thay
            cout << "\nHang hoa co gia " << X << " trieu dong:\n";

            // Tim va in cac hang hoa cung gia ben trai
            int i = mid;
            while (i >= 0 && a[i].gia == X)
                i--;

            // In cac hang hoa co gia X
            for (int k = i + 1; k < n && a[k].gia == X; k++) {
                cout << a[k].ma << "\t"
                     << a[k].ten << "\t"
                     << a[k].ngay << "/"
                     << a[k].thang << "/"
                     << a[k].nam << "\t"
                     << a[k].gia << endl;
            }

            timThay = true;
            break;
        }
        else if (a[mid].gia < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (!timThay)
        cout << "\nKhong tim thay hang hoa co gia " << X << endl;
}

// Cau 6: Ham main
int main() {
    HangHoa a[100];
    int n;
    float X;

    cout << "Nhap so luong hang hoa: ";
    cin >> n;

    // Nhap va xuat danh sach
    nhap(a, n);
    cout << "\nDanh sach hang hoa vua nhap:";
    xuat(a, n);

    // Sap xep tang dan theo gia
    quickSort(a, 0, n - 1);
    cout << "\nDanh sach sau khi sap xep:";
    xuat(a, n);

    // Tim hang hoa co gia bang X
    cout << "\nNhap gia X can tim: ";
    cin >> X;
    timKiem(a, n, X);

    return 0;
}
