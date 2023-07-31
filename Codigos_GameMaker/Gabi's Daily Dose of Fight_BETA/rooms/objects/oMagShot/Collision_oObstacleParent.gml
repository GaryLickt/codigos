/// @description Insert description here
// You can write your code in this editor
if room_get_name(room) != "RoomBoss1" {
instance_destroy(other);
instance_destroy();
audio_play_sound(choose(snd_dead2,snd_dead3),1,0)
}