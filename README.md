# Bài Tập Lớn - Quản lý Thư viện (baitaplon.cpp)

Một chương trình đơn giản viết bằng C++ để quản lý sách, sinh viên và phiếu mượn/trả. Chương trình sử dụng danh sách liên kết (linked list) cho từng loại đối tượng và cung cấp menu tương tác trên console để thêm, sửa, tìm kiếm, xóa và quản lý mượn trả sách.

## Tính năng chính
- Quản lý sách:
  - Thêm sách mới
  - Hiển thị danh sách sách
  - Tìm kiếm sách theo mã hoặc theo tên
  - Chỉnh sửa thông tin sách
  - Xóa sách
  - Sắp xếp sách theo tên (tăng dần)
- Quản lý sinh viên:
  - Thêm sinh viên mới
  - Hiển thị danh sách sinh viên
  - Tìm kiếm theo MSSV hoặc theo họ tên
  - Chỉnh sửa thông tin sinh viên
  - Xóa sinh viên
  - Sắp xếp theo MSSV (tăng dần)
- Quản lý mượn trả:
  - Lập phiếu mượn (liên kết với MSSV và mã sách đã tồn tại)
  - Hiển thị danh sách phiếu mượn
  - Trả sách (đánh dấu phiếu là đã trả)

## Yêu cầu
- Trình biên dịch C++ (g++ / clang++) hỗ trợ C++11 trở lên.
- Không có yêu cầu thư viện ngoài.

## Biên dịch và chạy

Dùng g++:
```bash
g++ -std=c++11 baitaplon.cpp -o baitaplon
./baitaplon
```

Hoặc với clang:
```bash
clang++ -std=c++11 baitaplon.cpp -o baitaplon
./baitaplon
```

## Cấu trúc chương trình (tóm tắt)
- Structs:
  - `Sach` — chứa mã sách, tên, tác giả, thể loại, con trỏ `next`.
  - `SinhVien` — chứa MSSV (long long), họ tên, lớp, con trỏ `next`.
  - `PhieuMuon` — chứa mã phiếu, MSSV, mã sách, ngày mượn (string), trạng thái trả, con trỏ `next`.
- Classes:
  - `QuanLySach` — quản lý danh sách sách và thao tác CRUD, tìm kiếm, sắp xếp.
  - `QuanLySinhVien` — quản lý danh sách sinh viên và thao tác CRUD, tìm kiếm, sắp xếp.
  - `QuanLyMuonTra` — quản lý danh sách phiếu mượn, sử dụng `QuanLySach` và `QuanLySinhVien` để kiểm tra ràng buộc.

## Hướng dẫn sử dụng (ví dụ)
1. Chạy chương trình:
   - Gõ `./baitaplon`.
2. Menu chính cho phép chọn:
   - 1: Quản lý sách
   - 2: Quản lý sinh viên
   - 3: Quản lý mượn trả
   - 0: Thoát
3. Ví dụ thao tác thêm sách:
   - Chọn 1 (Quản lý sách) -> chọn 1 (Thêm sách)
   - Nhập mã sách, tên sách, tác giả, thể loại.
4. Lập phiếu mượn:
   - Vào menu Quản lý mượn trả -> Lập phiếu mượn
   - Nhập mã phiếu, MSSV, mã sách, ngày mượn
   - Chương trình sẽ kiểm tra mã sách và MSSV có tồn tại hay không trước khi tạo phiếu.

Ví dụ tương tác:
```
Nhap lua chon: 1
--------- QUAN LY SACH ---------
Nhap lua chon: 1
Nhap ma sach: 101
Nhap ten sach: Lập trình C++
Nhap tac gia: Nguyen Van A
Nhap the loai: CNTT
Da them sach thanh cong!
```

## Hạn chế hiện tại
- Dữ liệu chỉ lưu trong bộ nhớ (không có lưu vào file), nên khi thoát chương trình thì mất dữ liệu.
- Không có kiểm tra trùng lặp mã sách, mã phiếu hay MSSV khi thêm (cần tránh nhập trùng tay thủ công).
- Lưu ngày mượn dưới dạng string (không chuẩn hóa, không kiểm tra định dạng ngày).
- Không có quản lý số lượng sách (mỗi mã sách được hiểu là một bản sao duy nhất).
- Phần tìm kiếm so sánh chính xác (exact match) cho tên và họ tên; không hỗ trợ tìm một phần (substring) hoặc không phân biệt hoa thường.
- Thiếu kiểm tra input chặt chẽ (nếu người dùng nhập sai kiểu dữ liệu, chương trình có thể đứng hoặc hành vi không mong muốn).
- Không có xử lý xóa liên quan (ví dụ: xóa sinh viên hay sách mà đang có phiếu mượn chưa trả).

## Gợi ý cải tiến
- Thêm lưu/đọc dữ liệu từ file (ví dụ CSV hoặc binary) để dữ liệu được bảo toàn giữa các lần chạy.
- Sử dụng STL (vector, list, map) thay cho con trỏ thô để dễ bảo trì.
- Cải thiện kiểm tra lỗi và validate input (ví dụ kiểm tra số nguyên, kiểm tra định dạng ngày).
- Hỗ trợ tìm kiếm theo phần chuỗi (substring) và không phân biệt hoa thường.
- Quản lý số lượng tồn kho cho mỗi sách (số bản có thể mượn).
- Khi xóa sách/sinh viên, kiểm tra và xử lý các phiếu mượn liên quan (khóa xóa nếu còn phiếu đang mượn).
- Tách định nghĩa struct/class ra các file header (*.h) và phần cài đặt ra *.cpp cho cấu trúc project lớn hơn.
- Viết unit tests cho các chức năng cốt lõi.
- Thêm giao diện đồ họa (GUI) hoặc giao diện web cho trải nghiệm người dùng tốt hơn.

## Phần ghi chú cho người phát triển
- Các hàm tim (timSachTheoMa, timSinhVienTheoMSSV, ...) trả con trỏ trực tiếp vào node trong danh sách; cẩn trọng khi chỉnh sửa/xóa node đó.
- Khi mở rộng chương trình, cân nhắc sử dụng smart pointers hoặc container STL để tránh leak bộ nhớ.
- Hiện tại chương trình dùng kiểu `int` cho maSach/maPhieu, `long long` cho MSSV — đảm bảo phù hợp với yêu cầu dữ liệu thực tế.

## Bản quyền
- File mẫu này là ví dụ học tập. Bạn có thể chỉnh sửa, mở rộng và phân phối lại theo nhu cầu cho mục đích học tập hoặc dự án nội bộ. Thêm license phù hợp nếu bạn muốn chia sẻ công khai (ví dụ MIT).

Nếu bạn muốn, tôi có thể:
- Viết phiên bản cải tiến có lưu/đọc file.
- Thêm kiểm tra trùng lặp khi thêm sách/sinh viên.
- Chuyển cấu trúc sang dùng STL (vector/list).
- Viết file header và tách code thành nhiều module.
Hãy cho biết bạn muốn cải tiến theo hướng nào.
