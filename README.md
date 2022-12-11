CÁC MODE: AUTO, MANUAL, CHANGE_VALUE, PEDESTRIAN

- Nhấn và thả SELECT_INDEX -> Mode Manual (Đợi hết đèn vàng mới được qua Manual)
	+ Nhấn MODIFY -> Đèn vàng -> Đổi sang đèn còn lại 
		VD: Đang ở Xanh -> Modify -> Vàng -> Đỏ
	+ Nhấn SET -> Đợi đèn vàng -> AUTO
	
- Nhấn giữ 3 giây SELECT -> MODE MODIFY TIME
	+ Nhấn SELECT_INDEX -> Đổi đèn
	+ Nhấn MODIFY_INDEX -> +1 value của đèn đó
	+ LONG_PRESSED_MODIFY + 10 value của đèn đó
	+ Nhấn SET_INDEX thì mới áp dụng giá trị mới của đèn
		* Sau khi nhấn SET thì đợi ... giây để về AUTO MODE
		* Trong thời gian đợi có thể nhấn SELECT để tiếp tục chỉnh thời gian

- Nhấn PEDESTRIAN -> Mode Pedestrian 
	Có 2 khả năng sảy ra: -> Chưa rõ lắm
		Đèn đỏ ở 4 hướng đều được bật để người đi bộ đi qua
		Đèn đỏ đối diện nhau bật thôi. (UNCLEAR) 

FUNCTION TO PUT INSIDE WHILE LOOP IN MAIN.C
- trafficLight_automatic()
- trafficLight_change()
- trafficLight_manual()
- trafficLight_pedestrian()
- triggerLed()


Adding new feature sound 