depth = -1000;

if image_xscale < maxscale {
image_xscale += 0.1;
}
if image_yscale < maxscale {
image_yscale += 0.1;
}



if place_meeting(x,y,oMouseCollision){
	if image_xscale < (maxscale+0.2) {
		image_xscale += 0.05;
	}
	if image_yscale < (maxscale+0.2) {
		image_yscale += 0.05;
	}
}else{
if image_xscale > maxscale {
image_xscale -= 0.05;
}
if image_yscale > maxscale {
image_yscale -= 0.05;
}
}