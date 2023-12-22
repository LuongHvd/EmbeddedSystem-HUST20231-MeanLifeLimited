# IT4210 Embedded Systems Course Project - Mean Life Limited Company
Repo này dùng để chứa mã nguồn và tiến trình của ba projects thực hiện, mỗi project giải quyết một vấn đề cụ thể và có ứng dụng trong đời sống hàng ngày. Phần dưới bao gồm tổng quan về mỗi dự án, hướng dẫn thiết lập, hướng dẫn sử dụng và đóng góp của nhóm.
## Contributors:
Hồ Viết Đức Lương - 20200376

Ngô Trần Anh Thư - 20200623

## Project for Embedded System
- Project 1: Hệ thống cảm biến khí ga và ngọn lửa báo cháy trong nhà bếp.
- Project 2: Hệ thống đo nhiệt độ - độ ẩm trong không khí.
- Project 3: Hiển thị hình ảnh PNG lên màn hình bộ kit STM32.

Mục tiêu của nhóm không chỉ là hoàn thành các yêu cầu của môn học mà còn là tạo ra những sản phẩm có giá trị thực tiễn, có thể áp dụng trong đời sống và có khả năng mở rộng trong tương lai.
## Các công nghệ sử dụng

## Project 1: Hệ thống cảm biến khí ga và ngọn lửa báo cháy trong nhà bếp
Trong dự án này, nhóm sẽ thiết kế và xây dựng một hệ thống cảm biến thông minh nhằm phát hiện khí ga và ngọn lửa trong nhà bếp. Hệ thống sẽ tích hợp các cảm biến đặc biệt (bao gồm sensor phát hiện khí gas và sensor phát hiện lửa) để nhận biết sớm các nguy cơ cháy nổ, từ đó kích hoạt hệ thống cảnh báo và tiến hành các biện pháp an toàn cần thiết.
### Công cụ phần cứng:
#### Kit ESP32-C3_Mini:

Dòng ESP32-C3 được xem là dòng low cost (giá rẻ) của ESPRESSIF tuy nhiên đây có thể được xem là dòng SoC phổ biến với những ưu điểm sau: Ngoại vi hỗ trợ mạnh: Bộ ADC, UART, I2C, SPI, … linh động, có thể mapping tới bất kì GPIO nào. Đồng thời số chân GPIO cũng nhiều hơn ESP8266 phù hợp với các ứng dụng cần nhiều GPIO.
Hỗ trợ BLE 5.0 long range: Đây là một trong những điểm cộng, vì nó có thể dùng trong các ứng dụng kết nối BLE cần khoảng cách xa (thu thập dữ liệu sensor) với chi phí thấp.
Hỗ trợ thuật mã hoá phần cứng (cho TLS/SSL): AES-128/AES-256 (FIPS PUB 197), ECB/CBC/OFB/CFB/CTR (NIST SP 800-38A), SHA1/SHA224/SHA256 (FIPS PUB 180-4), RSA3072, and ECC. Đây là một trong những thuật toán cơ bản cho kết nối MQTTS, HTTPS cũng như giao tiếp peer to peer.
Bộ nhớ RAM phù hợp cho các ứng dụng IoT.

Tính Năng:

Wi­Fi:
IEEE 802.11 b/g/n-compliant,
Supports 20 MHz, 40 MHz bandwidth in 2.4GHz band,
1T1R mode with data rate up to 150 Mbps,

Wi-Fi Multimedia (WMM):
TX/RX A-MPDU, TX/RX A-MSDU
Immediate Block ACK
Fragmentation and defragmentation
Transmit opportunity (TXOP)
Automatic Beacon monitoring (hardware TSF)
4 × virtual Wi-Fi interfaces
Simultaneous support for Infrastructure BSS in
Station mode, SoftAP mode, Station + SoftAP mode, and promiscuous mode.

Bluetooth:
Speed: 125 Kbps, 500 Kbps, 1 Mbps, 2 Mbps

CPU and Memory:
32-bit RISC-V single-core processor, up to 160 MHz
384 KB ROM
400 KB SRAM (16 KB for cache)
8 KB SRAM in RTC
Embedded flash (up to 4MB)

Advanced Peripheral Interfaces:
22 × programmable GPIOs

Digital interfaces:
3 × SPI,
2 × UART,
1 × I2C,
1 × I2S

2. Ứng dụng 

Smart Home
Light control
Smart button
Smart plug
Indoor positioning
Industrial Automation
Industrial robot
Mesh network
Human machine interface (HMI)
Industrial field bus
Health Care
Health monitor
Baby monitor
Consumer Electronics
Smart watch and bracelet
Over-the-top (OTT) devices
Wi-Fi and Bluetooth speaker
Logger toys and proximity sensing toys
Smart Agriculture
Smart greenhouse
Smart irrigation
Agriculture robot
Retail and Catering
POS machines
Service robot
Audio Device
Internet music players
Live streaming devices
Internet radio players
Generic Low-power IoT Sensor Hubs
Generic Low-power IoT Data Loggers

#### Sensor phát hiện khí ga MQ2
Cảm biến MQ-2 là một cảm biến khí dựa trên nguyên lý hoạt động của dòng điện đi qua một lớp chất bán dẫn khi tiếp xúc với khí. Được thiết kế đặc biệt để phát hiện các loại khí như khí CO (carbon monoxide), khí gas tự nhiên, và khí LPG (propane, butane). MQ-2 có khả năng phát hiện mức độ nồng độ khí trong môi trường và sản xuất tín hiệu analog dựa trên sự biến đổi điện trở.

Với sự nhỏ gọn, độ nhạy cao, và khả năng tương thích với nhiều dự án điện tử, cảm biến MQ-2 thường được sử dụng trong các ứng dụng như hệ thống cảnh báo cháy, hệ thống an toàn, và các dự án IoT liên quan đến giám sát chất khí. Điều này giúp đảm bảo an toàn và cảnh báo sớm về mức độ khí nguy hại trong môi trường. Ở project này, cảm biến được sử dụng để cảnh báo về nồng độ khí gas trong không khí.


#### Sensor ngọn lửa (Flame sensor)
Cảm biến ngọn lửa, hay còn được gọi là flame sensor, là một thiết bị quan trọng trong hệ thống an toàn và giám sát. Với khả năng nhận diện tia lửa hoặc ngọn lửa, cảm biến này đáp ứng nhanh chóng khi phát hiện nguy cơ cháy nổ. Hoạt động dựa trên sự phản xạ của tia lửa, cảm biến ngọn lửa tạo ra tín hiệu điện khi phát hiện ánh sáng từ ngọn lửa.

Sử dụng trong nhiều ứng dụng an toàn như hệ thống chữa cháy tự động, cảm biến ngọn lửa chơi vai trò quan trọng trong việc kích thích các biện pháp phòng ngừa hoặc cảnh báo sớm. Kết hợp với các hệ thống điều khiển và cảm biến khác, nó đóng vai trò quan trọng trong việc bảo vệ người và tài sản khỏi nguy cơ cháy nổ, làm tăng độ tin cậy và hiệu suất của hệ thống an toàn.

#### Còi chip 1.5-15V
Còi này để phát lên cảnh báo khi có nguy hiểm về lửa hoặc khí gas.

#### Đèn Led 3 màu Red Green Blue 
Đèn này dùng để cảnh báo: sẽ sáng đèn green nếu an toàn, đèn red nếu nguy hiểm.

### Công cụ Phần mềm
Arduino IDE, với Board ESP32-C3 Dev dùng để nạp code.

### Sơ đồ mạch

### Hoạt động của mạch


## Project 2: Hệ thống đo nhiệt độ - độ ẩm trong không khí
### Công cụ phần cứng và phần mềm
#### Phần cứng:
Kit ESP32-C3_Mini


#### Phần mềm
Arduino IDE, với Board ESP32-C3 Dev 

### Sơ đồ mạch

### Hoạt động của mạch



## Project 3: Hiển thị hình ảnh PNG lên màn hình bộ kit STM32
### Công cụ sử dụng: 
* TouchGFX Design version 4.23.0, available at: https://www.st.com/en/development-tools/touchgfxdesigner.html.
* STM32CubeIDE version 1.14.0.
* Bộ kit STM32F429I-DISC1.

### Cài đặt:
1. Clone repo này với lệnh: git clone https://github.com/yourusername/IT4210-Project3.git.
2. Cấu hình
3. Mở project bằng phần mềm IDE của bạn và cấu hình các driver cần thiết.
4. Nạp mã nguồn vào bộ kit STM32 của bạn.
5. Đảm bảo rằng mọi kết nối phần cứng đều chính xác.

### Sử dụng chương trình
