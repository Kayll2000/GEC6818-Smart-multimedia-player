CC=arm-linux-gcc -pthread
OBJ = main.o clear_lcd.o draw_ball.o draw_digit.o draw_frame.o draw_hline.o draw_point.o draw_rectangle.o draw_word.o get_pic_xy.o get_xy.o init.o init1.o lcd_drawbmp.o loading.o move_biaoti.o mydraw.o myid.o mymoveball.o myshow.o myshow1.o mysign.o mytouch.o myvideo.o show_bmp.o show_ct_bmp.o uinit.o white_back.o mysql.o show_time.o move_ball.o

main:$(OBJ)
	$(CC) -o $@ $^
main.o:main.c clearlcd.h draw_ball.h draw_digit.h draw_frame.h draw_hline.h draw_point.h draw_rectangle.h draw_word.h get_picxy.h get_xy.h init.h init1.h lcd_drawbmp.h loading.h move_biaoti.h mydraw.h myid.h mymoveball.h myshow.h myshow1.h mysign.h mytouch.h myvideo.h show_bmp.h show_ctbmp.h uinit.h white_back.h mysql.h move_ball.h show_time.h
	$(CC) -c $<
mysql.o:mysql.c mysql.h
	$(CC) -c $<
clear_lcd.o:clear_lcd.c clearlcd.h mysql.h
	$(CC) -c $<
draw_ball.o:draw_ball.c draw_ball.h mysql.h
	$(CC) -c $<
draw_digit.o:draw_digit.c draw_digit.h mysql.h
	$(CC) -c $<
draw_frame.o:draw_frame.c draw_frame.h mysql.h
	$(CC) -c $<
draw_hline.o:draw_hline.c draw_hline.h mysql.h
	$(CC) -c $<
draw_point.o:draw_point.c draw_point.h mysql.h
	$(CC) -c $<
draw_rectangle.o:draw_rectangle.c draw_rectangle.h mysql.h
	$(CC) -c $<
draw_word.o:draw_word.c draw_word.h mysql.h
	$(CC) -c $<
get_pic_xy.o:get_pic_xy.c get_picxy.h mysql.h
	$(CC) -c $<
get_xy.o:get_xy.c get_xy.h mysql.h
	$(CC) -c $<
show_time.o:show_time.c show_time.h mysql.h
	$(CC) -c $<
init.o:init.c init.h mysql.h
	$(CC) -c $<
init1.o:init1.c init1.h mysql.h
	$(CC) -c $<
lcd_drawbmp.o:lcd_drawbmp.c lcd_drawbmp.h mysql.h
	$(CC) -c $<
loading.o:loading.c loading.h mysql.h
	$(CC) -c $<
move_biaoti.o:move_biaoti.c move_biaoti.h mysql.h
	$(CC) -c $<
mydraw.o:mydraw.c mydraw.h mysql.h
	$(CC) -c $<
myid.o:myid.c myid.h mysql.h
	$(CC) -c $<
move_ball.o:move_ball.c move_ball.h mysql.h
	$(CC) -c $<	
mymoveball.o:mymoveball.c mymoveball.h mysql.h
	$(CC) -c $<
myshow.o:myshow.c myshow.h mysql.h
	$(CC) -c $<
myshow1.o:myshow1.c myshow1.h mysql.h
	$(CC) -c $<
myvideo.o:myvideo.c myvideo.h mysql.h
	$(CC) -c $<
show_bmp.o:show_bmp.c show_bmp.h mysql.h
	$(CC) -c $<
mysign.o:mysign.c mysign.h mysql.h
	$(CC) -c $<
mytouch.o:mytouch.c mytouch.h mysql.h
	$(CC) -c $<
show_ct_bmp.o:show_ct_bmp.c show_ctbmp.h mysql.h
	$(CC) -c $<
uinit.o:uinit.c uinit.h mysql.h
	$(CC) -c $<
white_back.o:white_back.c white_back.h mysql.h
	$(CC) -c $<

clean:
	rm -rf main $(OBJ)
