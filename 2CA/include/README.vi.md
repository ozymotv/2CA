[![C++](https://img.shields.io/badge/C%2B%2B-17-blue)](https://github.com/ozymotv/2CA)
[![License MIT](https://badgen.net/github/license/SunOner/sunone_aimbot_cpp)](https://github.com/SunOner/sunone_aimbot_cpp/blob/main/LICENSE)

> **⚠️ CẢNH BÁO:** TensorRT phiên bản 10 không hỗ trợ kiến trúc Pascal (card đồ họa dòng 10). Chỉ sử dụng với GPU từ dòng 20 trở lên.

## Hướng dẫn nhanh

### Bản cài đặt sẵn
1. **Tải CUDA**
   - Cài đặt [CUDA 12.8](https://developer.nvidia.com/cuda-12-8-0-download-archive)

2. **Tải bản phát hành mới nhất**
   - Tải về từ [đây](https://mega.nz/file/tKd2ySZL#nCKD-Lw-GEDzykpLZgTqQ8-Tc4hGAzN_KLySIdQnF-w) 

3. **Thiết lập**
   - Giải nén nội dung Aimbot
   - Chạy `ai.exe` và đợi cho quá trình xuất mô hình `.onnx` chuẩn (khoảng 5 phút)
   - Để sử dụng mô hình khác, đặt tệp `.onnx` của bạn vào thư mục `models` và chọn nó trong tab AI

4. **Điều khiển**
   - **Chuột phải:** Nhắm vào mục tiêu đã phát hiện
   - **F2:** Thoát chương trình
   - **F3:** Tạm dừng nhắm mục tiêu
   - **F4:** Tải lại cấu hình
   - **Home:** Mở overlay

## Cấu hình Kmbox Net
Phương thức chuột Kmbox Net mang lại nhiều ưu điểm:
- Độ chính xác cao hơn khi theo dõi mục tiêu
- Độ trễ phát hiện thấp hơn
- Cải thiện độ mượt mà khi di chuyển

Để kích hoạt Kmbox Net:
1. Mở overlay (phím Home)
2. Chuyển đến tab Mouse
3. Chọn "Kmbox Net" từ menu dropdown
4. Cấu hình kết nối theo nhu cầu

## Hướng dẫn xuất mô hình
Để xuất mô hình PyTorch từ Python với dynamic shapes:
```bash
pip install ultralytics -U
yolo export model=your_model.pt format=onnx dynamic=true simplify=true
```
Để chuyển đổi từ .onnx sang .engine, sử dụng tab export trong overlay.

## Tham khảo
- [Tài liệu cấu hình](https://github.com/SunOner/sunone_aimbot_docs/blob/main/config/config_cpp.md)
- [Dự án gốc](https://github.com/SunOner/sunone_aimbot_cpp)
