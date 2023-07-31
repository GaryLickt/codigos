var d = floor(direction/90);

switch(d){
case 0: image_xscale = 1;break;
case 1: image_xscale = -1;break;
case 2: image_xscale = -1;break;
case 3: image_xscale = 1;break;
}

if (place_meeting(x,y,oGabiBoss2)) and (batidas <= 0){
instance_destroy();
}

if batidas <= 0 {
move_towards_point(oGabiBoss2.x,oGabiBoss2.y,speed);
}

instance_create_layer(x,y-(sprite_height/2),"Instances",oWhiteRay);