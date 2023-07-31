/// @description Torso Attack Animation Start
// You can write your code in this editor
if oGabiBoss1.dead = false {
if hp >= 30 {
if prio = 3 {
if (atk2 = false) and (atk4 = false) {
	stop = true
	atk3 = true
	sprite_index = spr_marcoBossUlti;
	alarm[3] = 180;
}
prio = choose(2,4,4,4)
alarm[1] = choose(80,160,240);
alarm[2] = choose(80,160,240);
alarm[6] = choose(80,160,240);
}
}
}