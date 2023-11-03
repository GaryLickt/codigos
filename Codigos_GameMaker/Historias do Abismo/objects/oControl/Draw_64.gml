if instance_exists(oAllan) {
if oAllan.danger = true {
draw_sprite_ext(spr_dangersign1, 0, 20, 20, 2, 2, 0, c_white, 1);
}
}
if room_get_name(room) = "RoomOver" {
	layer_force_draw_depth(true,100)
switch(kill){
case 1: 
	oGameOverKiller.sprite_index = spr_teddy_chase;oGameOverKiller.image_xscale = 4;oGameOverKiller.image_yscale = 4;
	oGameOverScreen2.image_index = kill-1;
	break;
case 2: 
	oGameOverKiller.sprite_index = spr_banni_chase;oGameOverKiller.image_xscale = 4;oGameOverKiller.image_yscale = 4;
	oGameOverScreen2.image_index = kill-1;
	break;
case 3: 
	oGameOverKiller.sprite_index = spr_sasha_chase;oGameOverKiller.image_xscale = 4;oGameOverKiller.image_yscale = 4;
	oGameOverScreen2.image_index = kill-1;
	break;
case 4: 
	oGameOverKiller.sprite_index = spr_felix_chase;oGameOverKiller.image_xscale = 4;oGameOverKiller.image_yscale = 4;
	oGameOverScreen2.image_index = kill-1;
	break;
}

}