
#include "Header.h"

Node* taoNode(int a) {
    Node* Nodemoi = new Node;
    Nodemoi->so = a;
    Nodemoi->next = nullptr;
    return  Nodemoi;
};
void themNode(Node*& list, int a) { // them vao cuoi 
    Node* c = taoNode(a);
    if (list == nullptr) {
        list = c;
    }
    else {
        Node* p = list;
        while (p->next != nullptr)
        {
            p = p->next; // cho chay den cuoi list
        }
        p->next = c;
    }
}
void themDauNode(Node*& list, int a) {
    Node* b = taoNode(a);
    b->next = list;
    list = b;
}
void inList(Node* list) {
    Node* p = new Node;
    xoaDau(list);
    p = list;
    int a = 1; 
    if (p->so == 0 && p->dau == false) {
        list->dau = true;
    }
    while (p != nullptr ) {
        if (list->dau == false && a == 1 ) {
            cout << "-";
            a = 0; 
        }
        cout << p->so;
        p = p->next;
    }
}
Node* init(Node*& a) {
    return a = nullptr;
}
Node* Add(Node* a, Node* b) {
    Node* c = new Node;
    init(c);
    Node* k =coppyNode(a);
    Node* q = coppyNode(b) ;
    Node* d;
    Node* e;
    if (b->dau == false) {
        q->dau = true;
        c = Subtraction(k, q);
        return c;
    }
    if (a->dau == false && b->dau != false) {
        k->dau = true; 
        c = Subtraction(q, k);
        if (c->next->dau != false ) {
            c->dau = false ; 
        }
        return c; 
    }
    q = coppyNode(a);
    k = coppyNode(b);
    d = daoChuoi(q);
    e = daoChuoi(k);
    int tong = 0;
   
    while (d != nullptr || e != nullptr) {
        if (d != NULL && e != NULL) {
            tong += d->so + e->so;
        }
        else if (d == NULL && e != NULL) {
            tong += e->so;
        }
        else if (e == NULL && d != NULL) {
            tong += d->so;
        }
        if (tong >= 10) {
            tong = tong % 10;
            themDauNode(c, tong);
            tong = 1;
        }
        else {
            themDauNode(c, tong);
            tong = 0;
        }
        if (d != nullptr && e != nullptr) {
            d = d->next;
            e = e->next;
        }
        else if (d != nullptr && e == nullptr) {
            d = d->next;

        }
        else if (d == nullptr && e != nullptr) {
            e = e->next;
        }
    }
    if (tong == 1) {
        themDauNode(c, tong);
    }
    if (a->dau == false && b->dau == false) {
        themDauNode(c, 0);
        c->next->dau = false;
    }
    
    return c;
}
void xoaDau(Node*& a) {
    if (a != nullptr) {
        while (a->so == 0 && a->next != nullptr) {
            Node* temp = a;
            a = a->next;
            delete temp;
        }
    }
}
Node* daoChuoi(Node* head) {
    Node* pre = nullptr;
    Node* current = head;
    Node* next = nullptr;
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    while (current != nullptr) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }

    return pre;
}
Node* coppyNode(Node* list) {
    Node* newList = taoNode(list->so);
    newList->dau = list->dau;
    Node* curr = newList;
    Node* currGoc = list->next;
    while (currGoc != nullptr) {
        Node* moi = taoNode(currGoc->so);
        moi->dau = currGoc->dau;
        curr->next = moi;
        curr = curr->next;
        currGoc = currGoc->next;
    }

    return newList;
}
Node* Subtraction(Node* a, Node* b) {
    Node* a1 = coppyNode(a);
    Node* b1 = coppyNode(b);
    if (b1->dau == false) {
        b1->dau = true;
        Node* c = new Node;
        init(c);
        c = Add(a1, b1);
        return c;
    }
    if (a1->dau == false && b1->dau != false) {
        a1->dau = true; 
        Node* c = new Node;
        init(c);
        c = Add(a1, b1);
        themDauNode(c, 0);
        c->next->dau = false; 
        return c;
    }
    if(max(a1,b1) == a1) {
    Node* c = new Node;
    init(c);
    Node* k ;
    Node* q ;
    Node* soBiTru ;
    Node* soTru ;
    
    q = coppyNode(a);
    k = coppyNode(b);
    soBiTru = daoChuoi(q);
    soTru = daoChuoi(k);
    int hieu = 0;
    int muon = 0;
    
    while(soBiTru != nullptr || soTru != nullptr){
        if (soBiTru != nullptr && soTru != nullptr) {
            if (soBiTru->so - (soTru->so + muon) < 0) {
                hieu = (soBiTru->so + 10) - (soTru->so+muon);
                muon = 1;
            }
            else {
                hieu = soBiTru->so - (soTru->so+muon);
                muon = 0;
            }   
            themDauNode(c, hieu);
        }
        else if (soBiTru != NULL && soTru == NULL) {
            if (soBiTru->so - muon < 0) {
                themDauNode(c, soBiTru->so+10 - muon);
                muon = 1; 
            }
            else {
            themDauNode(c, soBiTru->so-muon);
            muon = 0;

            }
        }
       

        if (soBiTru != nullptr && soTru != nullptr) {
            soBiTru = soBiTru->next;
            soTru = soTru->next;
        }
        else if (soBiTru != nullptr && soTru == nullptr) {

            soBiTru = soBiTru->next;
        }
        else if (soBiTru == nullptr && soTru != nullptr) {

            soTru = soTru->next;
        }
    }
    return c; 
    }
    else if(max(a, b) == b){
        Node* u = new Node;
          u = Subtraction(b,a);
            Node* tmp = u;
          u->dau = false;

          while (u != nullptr) {
              u->dau = false;
              u = u->next;
          }
          u = tmp;
          return u; 
    }
}
Node* max(Node* a, Node* b) { //   xem lại hàm này vì 00 > 2 ;

        Node* k =a ;
        Node* q = b ;
        if (a->dau == true && b->dau == false) {
            return a;

        }
        else if (a->dau == false && b->dau ==true) {
            return b;
        } 
        k = a;  
        q = b;
       
        int count1 = 0;
        int count2 = 0;
        k = a;
        q = b;
        while (k->so == 0 && k->next != nullptr) {
            k = k->next;
        }
        while (q->so == 0 &&q->next != nullptr) {
            q = q->next;
        }
      
       while (q != nullptr) {
        count1++;
        q = q->next; 
       }
        while (k != nullptr) {
        count2++;
        k = k->next;
        }
        if (count1 > count2) {
            return b;
        }

        else if (count1 < count2) {
            return a;

        }
        else {
            k = a;
            q = b;
            while (k->so == 0 && k->next != nullptr) {
                k = k->next;
            }
            while (q->so == 0 && q->next != nullptr) {
                q = q->next;
            }
            while (k && q) {
                if (k->so > q->so) {
                    return a;   
                }
                else if (k->so < q->so) {
                    return b;
                }
                k = k->next;
                q = q->next;
            }
        }
        return a;

}
Node* times(Node* a, Node* b) {
    Node* a1 = coppyNode(a);
    Node* b1 = coppyNode(b);
    Node* c = new  Node;
    init(c);
    themNode(c, 0);
    Node* f = new  Node;
    init(f);
    Node* k;
    Node* q;
    bool am = false; 
    if (a1->dau == false && b1->dau == false) {
        a1->dau = true;
        b1->dau = true;
    }
    else if (a1->dau == false || b1->dau == false) {
        a1->dau = true;
        b1->dau = true;
        am = true;
    }

    Node* ab = daoChuoi(a1);
    Node* ac = daoChuoi(b1);
    k = coppyNode(ab);
    q = coppyNode(ac);
    int dem = 0, tong = 0, nho = 0; 
    while (q != nullptr) {
        while (k != nullptr) {
            tong = q->so * k->so+nho;
            if (tong > 10  && k->next !=nullptr) {
                nho = tong / 10;
                tong = tong % 10;
                themDauNode(f, tong);
            }
            else if (tong > 10 && k->next == nullptr) {
                themDauNode(f, tong % 10);
                themDauNode(f, tong / 10);
            }
            else {
                themDauNode(f, tong);
                nho = 0;
            }
            k = k->next;
        }
        q = q->next;
        dem++;
        nho = 0 ;
        k = coppyNode(ab);
        c= Add(c, f);
        init(f);
        for (int i = 0; i < dem; i++) {
            themDauNode(f, 0);
        }
    }
    if (am == true) {
        themDauNode(c, 0);
        c->next->dau = false; 
   }
    return c; 
}
void  Nhap(Node*& a) {
    string c;
    int e; 
    cout << "\n Moi ban nhap so : "; 
    cin >> c;
    
    if (c[0] == '-') {
        e = c[1] - '0';
        themNode(a, e);
        a->dau = false;
        for (int i = 2; i < c.length(); i++) {
            e = c[i] - '0';
            themNode(a, e);
        }
    }
    else {
        for (int i = 0; i < c.length(); i++) {
            e = c[i] - '0';
            themNode(a, e);
        }
    }
}
Node* Division(Node* a, Node* b) {
    Node* c = new  Node;    
    init(c);
    Node* p;
    int nho;
    if (b->so == 1 && b->next ==nullptr) {
        return a;
    }
    if (b->so == 0) {
        cout << "\n Khong the chia cho so ";
        return b;
    }
    bool am = false;
    Node* a1 = coppyNode(a);
    Node* b1 = coppyNode(b);
    if (a1->dau == false && b1->dau == false) {
        a1->dau = true;
        b1->dau = true;
    }
    else if (a1->dau == false || b1->dau == false) {
        a1->dau = true;
        b1->dau = true;
        am = true;
    }

    while (a1->dau!=false) {
        a1 = Subtraction(a1, b1);  
            if (c == nullptr) {
            themNode(c, -1);
        }
        c->so += 1;
        if (c->so == 10) {
            c->so = 0;
            nho = 1;
            p = c->next;
            while (nho!=0)
            {
                if (p == nullptr) {
                    themNode(c, 1);
                    nho = 0; 
                }
                else {
                    p->so += 1;
                    nho = 0;
                    if (p->so == 10) {
                        nho = 1;
                        p->so = 0;
                        p = p->next;
                    }
                }
            }
        }
    }
    
    c = daoChuoi(c);
    if (am == true) {
        themDauNode(c, 0);
        c->next->dau = false;
    }
    return c;
}

    void menu(Bang c[]) {
    int chon;
    system("CLS");
    const string fileName = "Data.txt";
    int b = 0;
    do {
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "| 1.Tao So               | 2. Tinh Toan                 |" << endl;
    cout << "|------------------------|------------------------------|" << endl;
    cout << "| 3. File                | 0. Thoat                     |" << endl;
    cout << "|------------------------|------------------------------|" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> chon;
    switch (chon) {
    case 1:
        subMenuTaoSo(c,b);
        break;
    case 2:
        if (b == 0) {
            cout << "\n Khong co so de tinh toan!";
            break;
        }
        int vitri1,vitri2;
        for (int i = 0; i < b; i++) {
            if (c[i] != nullptr) {
                cout << "(" << i << ")" << ".";
                inList(c[i]);
                cout << endl;
            }
        }
        cout << "\nChon so thu nhat : ";
        cin >> vitri1; 
        while (vitri1 >= b) {
            cout << "Vi tri sai , vui long nhap lai : "; 
            cin >> vitri1;
        }
        cout << "\nChon so thu hai : ";
        cin >> vitri2;
        while (vitri2 >= b) {
            cout << "Vi tri sai , vui long nhap lai : ";
            cin >> vitri2;
        }
        Node* a;
        Node* d; 
        a = c[vitri1];
        d = c[vitri2];
        
        subMenuTinhToan(a,d,c,b);
        break;
    case 3:
        subMenuFile(fileName,c,b);
        break;
   
    }
    } while (chon != 0);

}
    


void subMenuTinhToan(Node* a , Node* b , Bang c[] , int& e) {
    int chon;
    Node* f;
    system("CLS");
    do {
    cout << endl;
    cout << "|------------------------|------------------------------|" << endl;
    cout << "| 1. Cong                | 2. Tru                       |" << endl;
    cout << "|------------------------|------------------------------|" << endl;
    cout << "| 3. Nhan                | 4. Chia                      |" << endl;
    cout << "|------------------------|------------------------------|" << endl;
    cout << "| 0. Thoat               | 5. Thay doi so               |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "Nhap lua chon cua ban: ";
    cin >> chon;
    switch (chon) {
    case 1:
        system("CLS");
        inList(a);
        cout << " + ";
        inList(b);
        cout << " = " ;
         f = Add(a, b);
        inList(f);
        c[e] = f; 
        e++;
        break;
    case 2:
        system("CLS");
        inList(a);
        cout << " - ";
        inList(b);
        cout << " = ";
        f = Subtraction(a, b);
        inList(f);
        c[e] = f;
        e++;
        break;
    case 3:
        system("CLS");
        inList(a);
        cout << " * ";
        inList(b);
        cout << " = ";
        f = times(a, b);
        inList(f);
        c[e] = f;
        e++;
        break;
    case 4:
        system("CLS");
        inList(a);
        cout << " / ";
        inList(b);
        cout << " = ";
        f = Division(a, b);
        inList(f);
        c[e] = f;
        e++;
        break;
    case 5:
        for (int i = 0; i < e; i++) {
            if (c[i] != nullptr) {
                cout << "(" << i << ")" << ".";
                inList(c[i]);
                cout << endl;
            }
        }
        int vitri ;
        do{
        cout << "\nChon so thu nhat : ";
            cin >> vitri;
            a = c[vitri];
            cout << "\nChon so thu hai : ";
            cin >> vitri;
            b = c[vitri];
        } while (vitri > e);
        break; 
    }
    } while (chon != 0);
}
void subMenuTaoSo(Bang c[], int& b) {
    int chon; 
    system("CLS"); 
   do {
        cout << endl;
        cout << "|------------------------|------------------------------|" << endl;
        cout << "| 1. Tao So              | 2. Sua So                    |" << endl;
        cout << "|------------------------|------------------------------|" << endl;
        cout << "| 3. xoa so              | 4. Hien thi cac so hien co   |" << endl;
        cout << "|------------------------|------------------------------|" << endl;
        cout << "|                     0. Thoat                          |" << endl;
        cout << "|-------------------------------------------------------|" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;
    switch (chon) {
    case 1:
        system("CLS");
        Node* a;
        init(a);
        Nhap(a);
        cout << "\n So ban vua nhap la : "; 
        inList(a);
        if (b == 0) {
            c[b] = a;
            b++;

        }
        else {
            c[b] = a;
            b++;
        }
        break;
    case 2:
        system("CLS");

        int k;
        for (int i = 0; i < b; i++) {
            if (c[i] != nullptr) {
                cout << "(" << i << ")" << ".";
                inList(c[i]);
                cout << endl;
            }
        }
        cout << "\n Nhap vi tri  ban muon sua : ";
        cin >> k;   
        while (k >= b) {
            cout << "\n Vi tri sai ! Nhap lai : ";
            cin >> k;
        }
        Node* e;
        init(e);
        Nhap(e);
        c[k] = e; 
        for (int i = 0; i < b; i++) {
            if (c[i] != nullptr) {
                cout << "(" << i << ")" << ".";
                inList(c[i]);
                cout << endl;
            }
        }
        break;
    case 3:
        system("CLS");

        int vitri;
        for (int i = 0; i < b; i++) {
            if (c[i] != nullptr) {
                cout << "(" << i << ")" << ".";
                inList(c[i]);
                cout << endl;
            }
        }
        cout << "\n Nhap so muon xoa : ";
        cin >> vitri;
        for (int i = vitri; i < b; i++) {
            c[i] = c[i + 1];
        }
            c[b - 1] = nullptr; 
            delete c[b - 1];
            b--;
            if (b == 0) {
                cout << "\n Danh sach rong !";
            }
            else {
                for (int i = 0; i < b; i++) {
                    if (c[i] != nullptr) {
                        cout << "(" << i << ")" << ".";
                        inList(c[i]);
                        cout << endl;
                    }
                }
            }
      
        break;
    case 4:
        system("CLS");

        for (int i = 0; i < b; i++) {
            if (c[i] != nullptr) {
                cout << "(" << i << ")" << ".";
                inList(c[i]);
                cout << endl;
            }
        }
        break;
    }
    } while (chon != 0);

}
void subMenuFile(string  fileName, Bang c[],int& b ) {
    int chon;
    system("CLS");
    do {
        cout << endl;
        cout << "|------------------------|------------------------------|" << endl;
        cout << "| 1. Ghi file            | 2. Doc file                  |" << endl;
        cout << "|------------------------|------------------------------|" << endl;
        cout << "| 3. xoa  tat ca du lieu |                              |" << endl;
        cout << "|------------------------|------------------------------|" << endl;
        cout << "|                     0. Thoat                          |" << endl;
        cout << "|-------------------------------------------------------|" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        switch (chon) {
        case 1:
            system("CLS");
            for (int i = 0; i < b; i++) {
              ghiFile(c[i], fileName);
            }
            cout << "Ghi file thanh cong! ";
            break;
        case 2:
            system("CLS");
            docFile(fileName, b, c);
            break;
        case 3:
            system("CLS"); 
            xoaDL(fileName);
           break;
        case 4:
            system("CLS");
            break;
        }
    } while (chon != 0);
 
}

void ghiFile(Node* list, const string& fileName) {
    ofstream outputFile(fileName,ios_base::app);
    if (!outputFile.is_open()) {
        cout << "Khong mo duoc file !" << endl;
        return;
    }
    else {
        Node* p = list; 
        if (p->dau == false) {
            outputFile <<0;
        }
        while (p != nullptr) {
            outputFile << p->so;
            p = p->next;
        }
        outputFile << "\n";
        outputFile.close();
    }
}
void docFile(const string& fileName , int& b ,Bang c[]) {
    b = 0;
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Khong the mo file!" << endl;
        return ;
    }
    string data;
    while (getline(inputFile, data)) {
    Node* p; 
    init(p);
    nhapTuFile(p, data);
    c[b] = p;
    b++;
    }
    for (int i = 0; i < b; i++) {
        if (c[i] != nullptr) {
            cout << "(" << i << ")" << ".";
            inList(c[i]);
            cout << endl;
        }
    }

}

void nhapTuFile(Node*& a, string b) {
    int e;
    if (b[0]-'0' == 0) {
        e = b[1] - '0';
        themNode(a, e);
        a->dau = false;
        for (int i = 2; i < b.length(); i++) {
            e = b[i] - '0';
            themNode(a, e);
        }
    }
    else {
        for (int i = 0; i < b.length(); i++) {
            e =b[i] - '0';
            themNode(a, e);
        }
    }
}



void xoaDL(const string& fileName) {
    ofstream outputFile(fileName, ios_base::trunc);
    outputFile.close();
}










