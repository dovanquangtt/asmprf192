#include <stdio.h>  // Thu vien nhap xuat tieu chuan
#include <stdlib.h> // Thu vien ham chuan
#include <string.h> // Thu vien xu ly chuoi

#define MAX_ITEMS 100 // So luong mat hang toi da

struct Item { // Khai bao cau truc mot mat hang
    char name[50]; // Ten mat hang
    float price;   // Gia mat hang
    int quantity;  // So luong mat hang
};

struct Item bag[MAX_ITEMS]; // Mang luu tru cac mat hang
int num_items = 0;           // So luong mat hang hien tai

void create_item() { // Ham them mot mat hang moi vao tui
    if (num_items < MAX_ITEMS) { // Kiem tra tui co day khong
        printf("Enter item name: "); // Nhap ten mat hang
        scanf("%s", bag[num_items].name);
        printf("Enter item price: "); // Nhap gia mat hang
        scanf("%f", &bag[num_items].price);
        printf("Enter item quantity: "); // Nhap so luong mat hang
        scanf("%d", &bag[num_items].quantity);
        num_items++; // Tang so luong mat hang trong tui len 1
        printf("Item added successfully!\n"); // Thong bao mat hang da duoc them vao tui
    } else {
        printf("Bag is full!\n"); // Thong bao tui day
    }
}

void read_item() { // Ham doc thong tin mot mat hang tu tui
    char search_name[50]; // Ten mat hang can tim
    printf("Enter item name to search: "); // Nhap ten mat hang can tim
    scanf("%s", search_name);

    for (int i = 0; i < num_items; i++) { // Duyet qua tung mat hang trong tui
        if (strcmp(bag[i].name, search_name) == 0) { // So sanh ten mat hang voi ten can tim
            printf("Name: %s\n", bag[i].name); // In ra ten mat hang
            printf("Price: %.2f\n", bag[i].price); // In ra gia mat hang
            printf("Quantity: %d\n", bag[i].quantity); // In ra so luong mat hang
            return;
        }
    }
    printf("Item not found!\n"); // Thong bao khong tim thay mat hang
}

void update_item() { // Ham cap nhat thong tin mot mat hang trong tui
    char search_name[50]; // Ten mat hang can cap nhat
    printf("Enter item name to update: "); // Nhap ten mat hang can cap nhat
    scanf("%s", search_name);

    for (int i = 0; i < num_items; i++) { // Duyet qua tung mat hang trong tui
        if (strcmp(bag[i].name, search_name) == 0) { // So sanh ten mat hang voi ten can cap nhat
            printf("Enter new name (press enter to keep current): "); // Nhap ten moi (nhan enter de giu nguyen)
            scanf("%s", bag[i].name);
            printf("Enter new price (press enter to keep current): "); // Nhap gia moi (nhan enter de giu nguyen)
            scanf("%f", &bag[i].price);
            printf("Enter new quantity (press enter to keep current): "); // Nhap so luong moi (nhan enter de giu nguyen)
            scanf("%d", &bag[i].quantity);
            printf("Item updated successfully!\n"); // Thong bao mat hang da duoc cap nhat
            return;
        }
    }
    printf("Item not found!\n"); // Thong bao khong tim thay mat hang
}

void delete_item() { // Ham xoa mot mat hang khoi tui
    char search_name[50]; // Ten mat hang can xoa
    printf("Enter item name to delete: "); // Nhap ten mat hang can xoa
    scanf("%s", search_name);

    for (int i = 0; i < num_items; i++) { // Duyet qua tung mat hang trong tui
        if (strcmp(bag[i].name, search_name) == 0) { // So sanh ten mat hang voi ten can xoa
            for (int j = i; j < num_items - 1; j++) { // Di chuyen cac mat hang phia sau len mot vi tri de ghi de mat hang can xoa
                bag[j] = bag[j + 1];
            }
            num_items--; // Giam so luong mat hang trong tui
            printf("Item deleted successfully!\n"); // Thong bao mat hang da duoc xoa
            return;
        }
    }
    printf("Item not found!\n"); // Thong bao khong tim thay mat hang
}

void list_items() { // Ham hien thi danh sach mat hang trong tui
    if (num_items == 0) { // Kiem tra tui co trong khong
        printf("Bag is empty!\n"); // Thong bao tui trong
    } else {
        printf("Items in bag:\n"); // In ra danh sach mat hang trong tui
        for (int i = 0; i < num_items; i++) {
            printf("%d. Name: %s, Price: %.2f, Quantity: %d\n", i + 1, bag[i].name, bag[i].price, bag[i].quantity);
        }
    }
}

int main() { // Ham main
    int choice;
    while (1) { // Vong lap vo han de duy tri chuong trinh chay
        printf("\n1. Add Item\n"); // Menu lua chon
        printf("2. Update Item\n");
        printf("3. Delete Item\n");
        printf("4. List Items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Nhap lua chon

        switch (choice) { // Xu ly lua chon
            case 1:
                create_item(); // Them mat hang
                break;
            case 2:
                update_item(); // Cap nhat mat hang
                break;
            case 3:
                delete_item(); // Xoa mat hang
                break;
            case 4:
                list_items(); // Hien thi danh sach mat hang
                break;
            case 5:
                exit(0); // Thoat chuong trinh
            default:
                printf("Invalid choice! Please try again.\n"); // Lua chon khong hop le
        }
    }
    return 0;
}
