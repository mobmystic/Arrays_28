#include<iostream>
#include<math.h>
using namespace std;

bool squarenumber(int n) {
    int temp = sqrt(n);
    if(temp*temp == n) {
        return true;
    }
    return false;
}
bool prime(long long n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
bool perfectnumber(int n) {
    int aa = 0;
    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            aa += i;            
        }
    }
    if(aa == n) {
        return true;
    }
    return false;
}
bool tancung2(int n) {
    if(n % 10 == 2) {
        return true;
    }
    return false;
}
int main() {
    int arr[1000];
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap day so: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Menu thuc hien cong viec: " << endl;
    cout << "1. Sap xep day so theo chieu tang dan" << endl;
    cout << "2. Sap xep day so theo chieu giam dan" << endl;
    cout << "3. Tinh trung binh cong cac so le" << endl;
    cout << "4. Tim phan tu lon nhat, nho nhat cua day" << endl;
    cout << "5. In va tinh TBC cac so nguyen to" << endl;
    cout << "6. In cac so chinh phuong" << endl;
    cout << "7. In cac so hoan hao" << endl;
    cout << "8. In va tinh TBC cac so chia het cho 6 tan cung bang 2" << endl;
    int x;
    cout << "Nhap cong viec can lam: ";
    cin >> x;
    switch(x) {
        case 1:
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(arr[i] > arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            cout << "Day dc sap theo chieu tang dan: ";
            for(int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            break;
        case 2:
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(arr[i] < arr[j]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            cout << "Day dc sap theo chieu giam dan: ";
            for(int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            break;
        case 3:
            float tong;
            int count3;
            count3 = 0;
            for(int i = 0; i < n; i++) {
                if(arr[i] % 2 != 0) {
                    tong += arr[i];
                    count3++;
                }
            }
            cout << "TBC cac so le trong day: " << tong / count3;
            break;
        case 4:
            int max, min;
            max = arr[0];
            min = arr[0];
            for(int i = 0; i < n; i++) {
                if(arr[i] > max) {
                    max = arr[i];
                }
                if(arr[i] < min) {
                    min = arr[i];
                }
            }
            cout << "Phan tu lon nhat cua day: " << max << endl;
            cout << "Phan tu nho nhat cua day: " << min;
            break;
        case 5:
            float sum;
            int count5;
            count5 = 0;
            cout << "Cac so nguyen to trong day: ";
            for(int i = 0; i < n; i++) {
                if(prime(arr[i]) && arr[i] > 1) {
                    sum += arr[i];
                    count5++;
                    cout << arr[i] << " ";
                }   
            }
            cout << "\nTBC cac so nguyen to: " << sum / count5;
            break;
        case 6:
            cout << "Cac so chinh phuong trong day: ";
            for(int i = 0; i < n; i++) {
                if(squarenumber(arr[i]) && arr[i] > 1) {
                    cout << arr[i] << " ";
                }
            }
            break;
        case 7:
            cout << "Cac so hoan hao trong day: ";
            for(int i = 0; i < n; i++) {
                if(perfectnumber(arr[i])) {
                    cout << arr[i] << " ";
                }
            }
            break;
        case 8:
            float tong8;
            tong8 = 0;
            int count8;
            count8 = 0;
            cout << "Cac so chia het cho 6 tan cung bang 2: ";
            for(int i = 0; i < n; i++) {
                if(arr[i] % 6 == 0 && tancung2(arr[i])) {
                    tong8 += arr[i];
                    cout << arr[i] << " ";
                    count8++;
                }
            }
            cout << "\nTBC cac so chia het cho 6 tan cung bang 2: " << tong8 / count8;
            break;
    }
    return 0;
}