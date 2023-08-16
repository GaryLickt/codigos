randomize();

var id1 = layer_get_id("ts_predio");
var id2 = layer_get_id("ts_predio_secret");

var chanc = irandom_range(0,100);
	
	if chanc <= 10 {
		layer_set_visible(id1,false);
		layer_set_visible(id2,true);
	}else{
		layer_set_visible(id1,true);
		layer_set_visible(id2,false);
	}