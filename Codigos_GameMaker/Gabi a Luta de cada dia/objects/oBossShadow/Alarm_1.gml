/// @description Attack 1
// You can write your code in this editor
	if chanc <= 50 {
		var pos = irandom_range(0,45);
		repeat(8){
			var i = instance_create_layer(x,y,"Instances",kip);
			i.speed = 4;
			i.direction = pos;
			i.image_angle = pos;
			pos += 45;
		}
	}else{
	var i = instance_create_layer(x,y,"Instances",oBossShadowDente);
	i.speed = 4;
	i.direction = 0;
	i.image_angle = 0;
	
	var i1 = instance_create_layer(x,y,"Instances",oBossShadowDente);
	i1.speed = 4;
	i1.direction = 90;
	i1.image_angle = 90;
	
	var i2 = instance_create_layer(x,y,"Instances",oBossShadowDente);
	i2.speed = 4;
	i2.direction = 180;
	i2.image_angle = 180;
	
	var i3 = instance_create_layer(x,y,"Instances",oBossShadowDente);
	i3.speed = 4;
	i3.direction = 270;
	i3.image_angle = 270;
	}
