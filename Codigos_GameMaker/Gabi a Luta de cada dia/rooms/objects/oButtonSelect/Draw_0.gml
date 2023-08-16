if (oMainControl.level_map[# oCamera.stage-1, 0] >= 1) and (oMainControl.level_map[# oCamera.stage-1, 0] < 7) {
draw_self();
draw_set_font(f_levelselector);
draw_text(x-40,y+100,string(oCamera.stage) + " - " + string(oMainControl.level_map[# oCamera.stage-1, 0]))
draw_set_font(-1);
}