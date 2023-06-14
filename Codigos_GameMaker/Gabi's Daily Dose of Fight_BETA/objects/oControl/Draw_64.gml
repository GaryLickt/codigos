if room_get_name(room) != "RoomBoss1" {
draw_text(20, 10, oGabi.caos);
draw_text(20, 30, distance);

draw_text(20, 80, oGabi.skill1);
draw_text(20, 100, oGabi.skill2);
draw_text(20, 120, oGabi.skill3);
draw_text(20, 140, oGabi.skill4);

if passou == true {
draw_text((room_width/2)-20, 50, "FASE CONCLUIDA!!");
}
if yay == true {
draw_text((room_width/2)-20, 50, "GAME OVER!!");
draw_text((room_width/2)-20, 100, "Aperte ENTER para tentar novamente");
}
}