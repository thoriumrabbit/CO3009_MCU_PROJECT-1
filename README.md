CÁC MODE: AUTO, MANUAL, CHANGE_VALUE, PEDESTRIAN

- Nhấn và thả SELECT (A1 -PA1) -> Mode Manual (Đợi hết đèn vàng mới được qua Manual)
	+ Nhấn MODIFY (A2 - PA4) -> Đèn vàng -> Đổi sang đèn còn lại 
		VD: Đang ở Xanh -> Modify -> Vàng -> Đỏ
	+ Nhấn SET (A3 - PB0) -> Đợi đèn vàng -> AUTO
	
- Nhấn giữ 3 giây SELECT -> MODE MODIFY TIME
	+ Nhấn SELECT -> Đổi đèn
	+ Nhấn MODIFY -> +1 value của đèn đó
	+ LONG_PRESSED_MODIFY + 10 value của đèn đó
	+ Nhấn SET_INDEX thì mới áp dụng giá trị mới của đèn
		* Sau khi nhấn SET thì đợi ... giây để về AUTO MODE
		* Trong thời gian đợi có thể nhấn SELECT để tiếp tục chỉnh thời gian

- Nhấn PEDESTRIAN -> Mode Pedestrian 
	+ Đèn giao thông ở 4 nhánh vẫn hoạt động bình thường, không có thay đổi
	+ Nhấn PEDESTRIAN ở nhánh nào thì đèn PEDESTRIAN ở nhánh đó sẽ:
		* Bật đỏ nếu như đèn giao thông đang xanh và vàng
		* Bật xanh nếu như đèn giao thông đang đỏ
	+ Thời gian sáng: 1 chu kỳ đèn

FUNCTION TO PUT INSIDE WHILE LOOP IN MAIN.C
- trafficLight_automatic()
- trafficLight_change()
- trafficLight_manual()
- trafficLight_pedestrian()
- triggerLed()


Adding new feature sound 

- add usart2, baud rate 9600
- add TIM3_CH1, PA6

- change HCLK to 64MHz
- TIM2 change to PSC = 7999, ARR = 79, div 1 => 100Hz Clock
- TIM3 change to PSC = 63, ARR = 999, div 1 => 1000Hz Clock

