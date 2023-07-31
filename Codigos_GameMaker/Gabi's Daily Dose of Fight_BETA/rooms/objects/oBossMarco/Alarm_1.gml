/// @description Snake Attack Start
// You can write your code in this editor
if oGabiBoss1.dead = false {
if hp >= 30 {
if prio = 2 {
if (atk3 = false) and (atk4 = false) {
	sprite_index = spr_marcoBossSnake;
	stop = true;
	atk2 = true;
	alarm[5] = 1;
	alarm[8] = 120;
}
prio = choose(3,4,4,4)
alarm[1] = choose(80,160,240);
alarm[2] = choose(80,160,240);
alarm[6] = choose(80,160,240);
}
}
}