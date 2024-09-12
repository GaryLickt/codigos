package codigos.Codigos_JAVA.Mini_projetos.Date;

import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.Calendar;

public class Msg_Boas_Vindas_Calendar{

	public static void main(String[] args) {
		Calendar c1 = Calendar.getInstance();
		int hora = c1.get(Calendar.HOUR_OF_DAY);
		int minuto = c1.get(Calendar.MINUTE);

		LocalDateTime data1 = LocalDateTime.of(2015, 1, 1, 0, 0, 0);
		LocalDateTime data2 = LocalDateTime.of(2015, 1, 1, 0, 0, 0);

		long dias = data1.until(data2, ChronoUnit.DAYS);

		System.out.println(hora + ":" + minuto);
if(hora > 6 && hora < 12){
			System.out.println("Bom Dia");
		}else if(hora > 12 && hora < 18){
			System.out.println("Boa Tarde");
		}else{
			System.out.println("Boa Noite");
		}
	}
}