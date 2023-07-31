global.level = 2;
global.fase = 6;
global.highlevel = 1;
global.viu = false;

money = 0;


global.frases = ["OOF","Eita que pena","Tadinho","Ui, senti que tava quase indo","Ui quase, vacilou ai viu","Senti que ia ser melhor do que a ultima vez","Ok, ta ficando chato ja né?","Ainda tentando?","Mano, só desiste","Mais que pirralho insistente viu","Chato demais","Aff que chatisse","Mano tu morre de mais, é serio","Se tu morrer denovo eu desisto","Vou so ficar contando tuas mortes","16º Morte","17º Morte","18º Morte","19º Morte","20º Morte","21º Morte","O cara so faz morrer mano","Beleza, eu me demito","* o cara que fala as mensagens de morte se demitiu *","* ele não trabalha mais aqui *","* não tem ninguem vendo suas mortes aqui *","* ninguem mesmo *","* serio, não tem ninguem aqui *","* você morreu novamente *","* mas ninguem veio *"];
global.fras_count = 0;

global.totalmortes = 0;

global.sk1 = true;
global.sk2 = false;
global.sk3 = false;
global.sk4 = false;

level_map = ds_grid_create(5,1);

level_map[# 0, 0] = 7;
level_map[# 1, 0] = 6;
level_map[# 2, 0] = 0;
level_map[# 3, 0] = 0;
level_map[# 4, 0] = 0;