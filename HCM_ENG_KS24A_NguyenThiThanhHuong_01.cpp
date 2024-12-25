#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n = 0, choice, value, pos;

    while (1) { 
        printf("\n%23s\n", "MENU");
        printf("1. Nhap so phan tu va gia tri cua mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. In ra tong cua tat ca cac phan tu\n");
        printf("5. Them 1 phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Nhap phan tu muon tim trong mang\n");
        printf("9. Thoat chuong trinh\n");
        printf("Hay chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Nhap so luong phan tu: ");
                scanf("%d", &n);
                if (n > MAX_SIZE || n < 1) {
                    printf("So phan tu khong hop le!\n");
                    n = 0;
                } else {
                    printf("Nhap gia tri cho tung phan tu:\n");
                    for (int i = 0; i < n; i++) {
                        printf("arr[%d] = ", i);
                        scanf("%d", &arr[i]);
                    }
                    printf("Mang da duoc nhap xong.\n");
                }
                break;

            case 2: 
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    printf("Cac phan tu trong mang:\n");
                    for (int i = 0; i < n; i++) {
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;

            case 3: 
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    int min = arr[0], max = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] < min) {
                            min = arr[i];
                        }
                        if (arr[i] > max) {
                            max = arr[i];
                        }
                    }
                    printf("Gia tri nho nhat: %d\n", min);
                    printf("Gia tri lon nhat: %d\n", max);
                }
                break;

            case 4: 
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    int sum = 0;
                    for (int i = 0; i < n; i++) {
                        sum += arr[i];
                    }
                    printf("Tong cac phan tu trong mang: %d\n", sum);
                }
                break;

            case 5: 
                if (n >= MAX_SIZE) {
                    printf("Mang da day, khong the them phan tu moi.\n");
                } else {
                    printf("Nhap gia tri cua phan tu moi: ");
                    scanf("%d", &value);
                    arr[n++] = value;
                    printf("Them phan tu thanh cong. Mang hien tai:\n");
                    for (int i = 0; i < n; i++) {
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;

            case 6: 
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    printf("Nhap vi tri can xoa (0-%d): ", n - 1);
                    scanf("%d", &pos);
                    if (pos < 0 || pos >= n) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (int i = pos; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                        printf("Xoa phan tu thanh cong. Mang hien tai:\n");
                        for (int i = 0; i < n; i++) {
                            printf("arr[%d] = %d\n", i, arr[i]);
                        }
                    }
                }
                break;

            case 7: 
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = 0; j < n - i - 1; j++) {
                            if (arr[j] < arr[j + 1]) {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                    }
                    printf("Mang da duoc sap xep giam dan:\n");
                    for (int i = 0; i < n; i++) {
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;

            case 8: 
                if (n == 0) {
                    printf("Mang chua co phan tu nao.\n");
                } else {
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &value);
                    int found = 0;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == value) {
                            printf("Phan tu %d xuat hien o vi tri arr[%d].\n", value, i);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("Khong tim thay phan tu %d trong mang.\n", value);
                    }
                }
                break;

            case 9:
                printf("Thoat chuong trinh. Cam on da su dung!\n");
                return 0;

            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    }

    return 0;
}

