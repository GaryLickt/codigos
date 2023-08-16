if instance_exists(oAllan) {
	#region Usando ou Não a Habilidade
	if oAllan.visi = false {
		var _lay = layer_get_id("ts_wall");
		var _laycursed = layer_get_id("ts_wallcursed");
		layer_set_visible(_lay,true);
		layer_set_visible(_laycursed,false);
		var _lay1 = layer_get_id("ts_ground");
		var _laycursed1 = layer_get_id("ts_groundcursed");
		layer_set_visible(_lay1,true);
		layer_set_visible(_laycursed1,false);
	}else{
		var _lay = layer_get_id("ts_wall");
		var _laycursed = layer_get_id("ts_wallcursed");
		layer_set_visible(_lay,false);
		layer_set_visible(_laycursed,true);
		var _lay1 = layer_get_id("ts_ground");
		var _laycursed1 = layer_get_id("ts_groundcursed");
		layer_set_visible(_lay1,false);
		layer_set_visible(_laycursed1,true);
	}
	#endregion

kill = oAllan.killer;
	if (oAllan.dead = false) {
if (oAllan.danger = true) and (oAllan.visi = false){
	if (audio_is_playing(snd_h1ambient)) {
		audio_stop_sound(snd_h1ambient);
	}
	if (audio_is_playing(snd_h1clock)) {
		audio_stop_sound(snd_h1clock);
	}
	if !(audio_is_playing(snd_h1heartbeat)) {
		audio_play_sound(snd_h1heartbeat, 5, true);
	}
}
if (oAllan.danger = false) {
	if (audio_is_playing(snd_h1heartbeat)) {
		audio_stop_sound(snd_h1heartbeat);
	}
	if !(audio_is_playing(snd_h1ambient)) {
		audio_play_sound(snd_h1ambient, 5, true);
	}
	if !(audio_is_playing(snd_h1clock)) {
		audio_play_sound(snd_h1clock, 5, true);
	}
	if audio_is_playing(snd_h1susbient) {
		audio_stop_sound(snd_h1susbient);
	}
}

if oAllan.visi = true {
	if audio_is_playing(snd_h1susbient) {
		audio_stop_sound(snd_h1susbient);
	}
	if audio_is_playing(snd_h1heartbeat) {
		audio_stop_sound(snd_h1heartbeat);
	}
	if audio_is_playing(snd_h1ambient) {
		audio_stop_sound(snd_h1ambient);
	}
	if audio_is_playing(snd_h1clock) {
		audio_stop_sound(snd_h1clock);
	}
}


if ((oAllan.danger = true) and (oAllan.detect = false)) and (oAllan.visi = false) {
	if !(audio_is_playing(snd_h1susbient)) {
		audio_play_sound(snd_h1susbient, 5, true);
	}
}

if (oAllan.detect = true) {
	if !audio_is_playing(snd_h1chase){
		audio_play_sound(snd_h1chase, 5, true);
	}
	if audio_is_playing(snd_h1susbient) {
		audio_stop_sound(snd_h1susbient);
	}
}
if (oAllan.detect = false) {
	if audio_is_playing(snd_h1chase){
		audio_stop_sound(snd_h1chase);
	}
}
}else{
audio_stop_all();
last_room = room;
room_goto(RoomOver);
}
}