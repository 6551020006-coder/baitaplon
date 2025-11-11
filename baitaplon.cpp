#include <iostream>
#include <string>
using namespace std;

// ================= CẤU TRÚC DỮ LIỆU =================
struct Sach {
    int maSach;
    string tenSach;
    string tacGia;
    string theLoai;
    Sach* next;
};

struct SinhVien {
    long long MSSV;
    string hoTen;
    string lop;
    SinhVien* next;
};

struct PhieuMuon {
    int maPhieu;
    long long MSSV;
    int maSach;
    string ngayMuon;
    bool daTra;
    PhieuMuon* next;
};

// ================= CLASS QUẢN LÝ SÁCH =================
class QuanLySach {
private:
    Sach* head;
public:
    QuanLySach();
    void themSach();
    void hienThiSach();
    void sapXepTheoTen();
    void timKiem();
    Sach* timSachTheoMa(int ma);
    Sach* timSachTheoTen(string& ten);
    void chinhSuaSach();
    void xoaSach();
    
};

// ================= CLASS QUẢN LÝ SINH VIÊN =================
class QuanLySinhVien {
private:
    SinhVien* head;
public:
    QuanLySinhVien();
    void themSinhVien();
    void hienThiSinhVien();
    void sapXepTheoMSSV();
    void timKiem();
    SinhVien* timSinhVienTheoMSSV(int mssv);
    SinhVien* timSinhVienTheoTen(const string& ten);
    void chinhSuaSinhVien();
    void xoaSinhVien();
};

// ================= CLASS QUẢN LÝ MƯỢN TRẢ =================
class QuanLyMuonTra {
private:
    PhieuMuon* head;
    QuanLySach* qls;
    QuanLySinhVien* qlsv;
public:
    QuanLyMuonTra(QuanLySach* s, QuanLySinhVien* sv);
    void lapPhieuMuon();
    void hienThiPhieuMuon();
    void trasach();
};

// =======================================================
// =============== HÀM CỦA QUẢN LÝ SÁCH ==================
// =======================================================

QuanLySach::QuanLySach() {
    head = NULL;
}

void QuanLySach::themSach() {
    Sach* s = new Sach;
    cout << "Nhap ma sach: "; cin >> s->maSach;
    cin.ignore();
    cout << "Nhap ten sach: "; getline(cin, s->tenSach);
    cout << "Nhap tac gia: "; getline(cin, s->tacGia);
    cout << "Nhap the loai: "; getline(cin, s->theLoai);
    s->next = NULL;

    if (head == NULL) head = s;
    else {
        Sach* p = head;
        while (p->next != NULL) p = p->next;
        p->next = s;
    }
    cout << "Da them sach thanh cong!\n";
}

void QuanLySach::hienThiSach() {
    if (head == NULL) {
        cout << "Danh sach sach rong!\n";
        return;
    }
    Sach* p = head;
    cout << "\n===== DANH SACH SACH =====\n";
    while (p != NULL) {
        cout << "Ma sach: " << p->maSach << endl;
        cout << "Ten sach: " << p->tenSach << endl;
        cout << "Tac gia: " << p->tacGia << endl;
        cout << "The loai: " << p->theLoai << endl;
        cout << "----------------------\n";
        p = p->next;
    }
}

void QuanLySach::sapXepTheoTen() {
    if (head == NULL || head->next == NULL) return;

    for (Sach* i = head; i->next != NULL; i = i->next) {
        for (Sach* j = i->next; j != NULL; j = j->next) {
            if (i->tenSach > j->tenSach) {
                // Trao doi maSach
                int tmpMa = i->maSach;
                i->maSach = j->maSach;
                j->maSach = tmpMa;

                // Trao doi tenSach
                string tmpTen = i->tenSach;
                i->tenSach = j->tenSach;
                j->tenSach = tmpTen;

                // Trao doi tacGia
                string tmpTacGia = i->tacGia;
                i->tacGia = j->tacGia;
                j->tacGia = tmpTacGia;

                // Trao doi theLoai
                string tmpTheLoai = i->theLoai;
                i->theLoai = j->theLoai;
                j->theLoai = tmpTheLoai;
            }
        }
    }

    cout << "Da sap xep sach theo ten (tang dan)\n";
}


Sach* QuanLySach::timSachTheoMa(int ma) {
    Sach* p = head;
    while (p != NULL) {
        if (p->maSach == ma) return p;
        p = p->next;
    }
    return NULL;
}
Sach* QuanLySach::timSachTheoTen(string& ten) {
        Sach* p = head;
        while (p != NULL) {
            if (p->tenSach == ten)
                return p;
            p = p->next;
        }
        return NULL;
    }

void QuanLySach::timKiem() {
        if (head == NULL) {
            cout << "Danh sach rong!\n";
            return;
        }
        int lua;
        cout << "1. Tim theo ma sach\n2. Tim theo ten sach\nChon: ";
        cin >> lua;
        cin.ignore(); 
        if (lua == 1) {
            int ma;
            cout << "Nhap ma sach: ";
            cin >> ma;
            Sach* s = timSachTheoMa(ma);
            if (s)
                cout << "Tim thay sach: " << s->tenSach << " - Tac gia: " << s->tacGia << endl;
            else
                cout << "Khong tim thay!\n";
        } else if (lua == 2) {
            string ten;
            cout << "Nhap ten sach: ";
            getline(cin, ten);
            Sach* s = timSachTheoTen(ten);
            if (s)
                cout << "Tim thay sach ma " << s->maSach << " - Tac gia: " << s->tacGia << endl;
            else
                cout << "Khong tim thay!\n";
        } else {
            cout << "Lua chon khong hop le!\n";
        }
    }
    
void QuanLySach::chinhSuaSach() {
    if (head == NULL) {
        cout << "Danh sach sach rong!\n";
        return;
    }

    int ma;
    cout << "Nhap ma sach can chinh sua: ";
    cin >> ma;

    Sach* s = timSachTheoMa(ma);
    if (s == NULL) {
        cout << "Khong tim thay ma sach!\n";
        return;
    }
    cin.ignore();
    cout << "Nhap ten sach moi (de trong neu khong doi): ";
    string ten; getline(cin, ten);
    if (!ten.empty()) s->tenSach = ten;

    cout << "Nhap tac gia moi (de trong neu khong doi): ";
    string tg; getline(cin, tg);
    if (!tg.empty()) s->tacGia = tg;

    cout << "Nhap the loai moi (de trong neu khong doi): ";
    string tl; getline(cin, tl);
    if (!tl.empty()) s->theLoai = tl;

    cout << "Da cap nhat thong tin sach thanh cong!\n";
}

void QuanLySach::xoaSach() {
    if (head == NULL) {
        cout << "Danh sach sach rong!\n";
        return;
    }

    int ma;
    cout << "Nhap ma sach can xoa: ";
    cin >> ma;

    Sach* p = head;
    Sach* truoc = NULL;

    while (p != NULL && p->maSach != ma) {
        truoc = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Khong tim thay ma sach!\n";
        return;
    }

    if (truoc == NULL) { 
        head = p->next;
    } else {
        truoc->next = p->next;
    }

    delete p;
    cout << "Da xoa sach thanh cong!\n";
}

// =======================================================
// ============ HÀM CỦA QUẢN LÝ SINH VIÊN ================
// =======================================================

QuanLySinhVien::QuanLySinhVien() {
    head = NULL;
}

void QuanLySinhVien::themSinhVien() {
    SinhVien* sv = new SinhVien;
    
    cout << "Nhap MSSV: "; cin >> sv->MSSV;
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, sv->hoTen);
    cout << "Nhap lop: "; getline(cin, sv->lop);
    
    sv->next = NULL;
    if (head == NULL) head = sv;
    else {
        SinhVien* p = head;
        while (p->next != NULL) p = p->next;
        p->next = sv;
    }
    cout << "Da them sinh vien thanh cong!\n";
}

void QuanLySinhVien::hienThiSinhVien() {
    if (head == NULL) {
        cout << "Danh sach sinh vien rong!\n";
        return;
    }
    
    SinhVien* p = head;
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    while (p != NULL) {
        cout << "MSSV: " << p->MSSV << endl;
        cout << "Ho ten: " << p->hoTen << endl;
        cout << "Lop: " << p->lop << endl;
        cout << "----------------------\n";
        p = p->next;
    }
}

void QuanLySinhVien::sapXepTheoMSSV() {
    if (head == NULL || head->next == NULL) return;

    for (SinhVien* i = head; i->next != NULL; i = i->next) {
        for (SinhVien* j = i->next; j != NULL; j = j->next) {
            if (i->MSSV > j->MSSV) {
                // Trao doi MSSV
                int tmpMSSV = i->MSSV;
                i->MSSV = j->MSSV;
                j->MSSV = tmpMSSV;

                // Trao doi hoTen
                string tmpHoTen = i->hoTen;
                i->hoTen = j->hoTen;
                j->hoTen = tmpHoTen;

                // Trao doi lop
                string tmpLop = i->lop;
                i->lop = j->lop;
                j->lop = tmpLop;
            }
        }
    }

    cout << "Da sap xep sinh vien theo MSSV (tang dan)\n";
}


SinhVien* QuanLySinhVien::timSinhVienTheoMSSV(int mssv) {
    SinhVien* p = head;
    while (p != NULL) {
        if (p->MSSV == mssv) return p;
        p = p->next;
    }
    return NULL;
}

SinhVien* QuanLySinhVien::timSinhVienTheoTen(const string& ten) {
        SinhVien* p = head;
        while (p != NULL) {
            if (p->hoTen == ten)
                return p;
            p = p->next;
        }
        return NULL;
}

 void QuanLySinhVien::timKiem() {
        if (head == NULL) {
            cout << "Danh sach rong!\n";
            return;
        }

        int lua;
        cout << "1. Tim theo MSSV\n2. Tim theo ho ten\nChon: ";
        cin >> lua;
        cin.ignore();

        if (lua == 1) {
            int mssv;
            cout << "Nhap MSSV: ";
            cin >> mssv;
            SinhVien* s = timSinhVienTheoMSSV(mssv);
            if (s)
                cout << "Tim thay: " << s->hoTen << " - Lop: " << s->lop << endl;
            else
                cout << "Khong tim thay!\n";

        } else if (lua == 2) {
            string ten;
            cout << "Nhap ho ten: ";
            getline(cin, ten);
            SinhVien* s = timSinhVienTheoTen(ten);
            if (s)
                cout << "Tim thay: MSSV " << s->MSSV << " - Lop: " << s->lop << endl;
            else
                cout << "Khong tim thay!\n";
        } else {
            cout << "Lua chon khong hop le!\n";
        }
    }
    
void QuanLySinhVien::chinhSuaSinhVien() {
    if (head == NULL) {
        cout << "Danh sach sinh vien rong!\n";
        return;
    }

    int mssv;
    cout << "Nhap MSSV can chinh sua: ";
    cin >> mssv;

    SinhVien* sv = timSinhVienTheoMSSV(mssv);
    if (sv == NULL) {
        cout << "Khong tim thay sinh vien!\n";
        return;
    }

    cin.ignore();
    cout << "Nhap ho ten moi (de trong neu khong doi): ";
    string ten; getline(cin, ten);
    if (!ten.empty()) sv->hoTen = ten;

    cout << "Nhap lop moi (de trong neu khong doi): ";
    string lop; getline(cin, lop);
    if (!lop.empty()) sv->lop = lop;

    cout << "Da cap nhat thong tin sinh vien!\n";
}


void QuanLySinhVien::xoaSinhVien() {
    if (head == NULL) {
        cout << "Danh sach sinh vien rong!\n";
        return;
    }

    int mssv;
    cout << "Nhap MSSV can xoa: ";
    cin >> mssv;

    SinhVien* p = head;
    SinhVien* truoc = NULL;

    while (p != NULL && p->MSSV != mssv) {
        truoc = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Khong tim thay sinh vien!\n";
        return;
    }

    if (truoc == NULL) {
        head = p->next;
    } else {
        truoc->next = p->next;
    }

    delete p;
    cout << "Da xoa sinh vien thanh cong!\n";
}

// =======================================================
// ============ HÀM CỦA QUẢN LÝ MƯỢN TRẢ ================
// =======================================================

QuanLyMuonTra::QuanLyMuonTra(QuanLySach* s, QuanLySinhVien* sv) {
    head = NULL;
    qls = s;
    qlsv = sv;
}

void QuanLyMuonTra::lapPhieuMuon() {
    PhieuMuon* pm = new PhieuMuon;
    cout << "Nhap ma phieu: "; cin >> pm->maPhieu;
    cout << "Nhap MSSV: "; cin >> pm->MSSV;
    cout << "Nhap ma sach: "; cin >> pm->maSach;
    cin.ignore();
    cout << "Nhap ngay muon: "; getline(cin, pm->ngayMuon);
    pm->daTra = false;
    pm->next = NULL;

    if (qls->timSachTheoMa(pm->maSach) == NULL) {
        cout << "Khong tim thay ma sach!\n";
        delete pm;
        return;
    }
    if (qlsv->timSinhVienTheoMSSV(pm->MSSV) == NULL) {
        cout << "Khong tim thay MSSV!\n";
        delete pm;
        return;
    }

    if (head == NULL) head = pm;
    else {
        PhieuMuon* p = head;
        while (p->next != NULL) p = p->next;
        p->next = pm;
    }
    cout << "Da lap phieu muon thanh cong!\n";
}

void QuanLyMuonTra::hienThiPhieuMuon() {
    if (head == NULL) {
        cout << "Chua co phieu muon!\n";
        return;
    }
    PhieuMuon* p = head;
    cout << "\n===== DANH SACH PHIEU MUON =====\n";
    while (p != NULL) {
        cout << "Ma phieu: " << p->maPhieu << endl;
        cout << "MSSV: " << p->MSSV << endl;
        cout << "Ma sach: " << p->maSach << endl;
        cout << "Ngay muon: " << p->ngayMuon << endl;
        cout << "Trang thai: " << (p->daTra ? "Da tra" : "Dang muon") << endl;
        cout << "----------------------\n";
        p = p->next;
    }
}
void QuanLyMuonTra::trasach() {
    if (head == NULL) {
        cout << "Chua co phieu muon!\n";
        return;
    }

    int mssv, maSach;
    cout << "Nhap MSSV: "; cin >> mssv;
    cout << "Nhap ma sach muon tra: "; cin >> maSach;

    PhieuMuon* p = head;
    bool found = false;

    while (p != NULL) {
        if (p->MSSV == mssv && p->maSach == maSach && !p->daTra) {
            p->daTra = true;
            cout << "Da tra sach thanh cong!\n";
            found = true;
            break;
        }
        p = p->next;
    }

    if (!found)
        cout << "Khong tim thay phieu muon hoac sach da tra roi!\n";
}

// =======================================================
// ====================== MAIN ===========================
// =======================================================
 int main() {
    QuanLySach qls;
    QuanLySinhVien qlsv;
    QuanLyMuonTra qlmt(&qls, &qlsv);

    int chon = -1;

    while (chon != 0) {
        cout << "\n===================== MENU CHINH =====================\n";
        cout << "1. Quan ly sach\n";
        cout << "2. Quan ly sinh vien\n";
        cout << "3. Quan ly muon tra\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "======================================================\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        if (chon == 1) {
            int c1 = -1;
            while (c1 != 0) {
                cout << "\n--------- QUAN LY SACH ---------\n";
                cout << "1. Them sach\n";
                cout << "2. Hien thi danh sach sach\n";
                cout << "3. Tim kiem sach\n";
                cout << "4. Chinh sua thong tin sach\n";
                cout << "5. Xoa sach\n";
                cout << "0. Quay lai menu chinh\n";
                cout << "--------------------------------\n";
                cout << "Nhap lua chon: ";
                cin >> c1;

                if (c1 == 1)
                    qls.themSach();
                else if (c1 == 2)
                    qls.hienThiSach();
                else if (c1 == 3)
                   qls.timKiem();
                else if (c1 == 4)
                    qls.chinhSuaSach();
                else if (c1 == 5)
                    qls.xoaSach();
                else if (c1 == 0)
                    cout << "Quay lai menu chinh...\n";
                else
                    cout << "Lua chon khong hop le!\n";
            }
        }

        else if (chon == 2) {
            int c2 = -1;
            while (c2 != 0) {
                cout << "\n------ QUAN LY SINH VIEN ------\n";
                cout << "1. Them sinh vien\n";
                cout << "2. Hien thi danh sach sinh vien\n";
                cout << "3. Sap xep sinh vien theo MSSV\n";
                cout << "4. Tim kiem sinh vien\n";
                cout << "5. Chinh sua thong tin sinh vien\n";
                cout << "6. Xoa sinh vien\n";
                cout << "0. Quay lai menu chinh\n";
                cout << "-------------------------------\n";
                cout << "Nhap lua chon: ";
                cin >> c2;

                if (c2 == 1)
                    qlsv.themSinhVien();
                else if (c2 == 2)
                    qlsv.hienThiSinhVien();
                else if (c2 == 3)
                    qlsv.sapXepTheoMSSV();
                else if (c2 == 4)
                    qlsv.timKiem();
                else if (c2 == 5)
                    qlsv.chinhSuaSinhVien();
                else if (c2 == 6)
                    qlsv.xoaSinhVien();
                else if (c2 == 0)
                    cout << "Quay lai menu chinh...\n";
                else
                    cout << "Lua chon khong hop le!\n";
            }
        }

        else if (chon == 3) {
            int c3 = -1;
            while (c3 != 0) {
                cout << "\n------ QUAN LY MUON TRA ------\n";
                cout << "1. Lap phieu muon sach\n";
                cout << "2. Hien thi danh sach phieu muon\n";
                cout << "3. Tra sach\n";
                cout << "0. Quay lai menu chinh\n";
                cout << "-------------------------------\n";
                cout << "Nhap lua chon: ";
                cin >> c3;

                if (c3 == 1)
                    qlmt.lapPhieuMuon();
                else if (c3 == 2)
                    qlmt.hienThiPhieuMuon();
                else if (c3 == 3)
                    qlmt.trasach();
                else if (c3 == 0)
                    cout << "Quay lai menu chinh...\n";
                else
                    cout << "Lua chon khong hop le!\n";
            }
        }

        else if (chon == 0) {
            cout << "\nTam biet! Ket thuc chuong trinh.\n";
        }

        else {
            cout << "Lua chon khong hop le, vui long nhap lai!\n";
        }
    }

    return 0;
}


