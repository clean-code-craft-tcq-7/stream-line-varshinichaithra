package Sender;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class SenderServiceImpl implements SenderService {
	private static ILogger log = new Logger();
	Random random = new Random();
	List<SenderParam> streamData = new ArrayList<SenderParam>();
	public static int MAX_TEMPERATURE = 40;
	public static int MIN_TEMPERATURE = 0;
	public static int MAX_SOC = 80;
	public static int MIN_SOC = 20;
	public static final float MAX_CHARGE_RATE = 0.8f;
	public static final float MIN_CHARGE_RATE = 0.0f;

	public List<SenderParam> receiveReadingsFromBattery(int readingcount) {

		for (int i = 1; i <= readingcount; i++) {

			int temperatureValue = getRandomValue(MAX_TEMPERATURE, MIN_TEMPERATURE);
			int SocValue = getRandomValue(MAX_SOC, MIN_SOC);
			DecimalFormat df = new DecimalFormat("#.#");
			float ChargeValue = Float.valueOf(df.format(getRandom(MAX_CHARGE_RATE, MIN_CHARGE_RATE)));
			streamData.add(new SenderParam(temperatureValue, SocValue, ChargeValue));
		}
		return streamData;
	}

	public void sendReadingsToConsole() {
		log.setMessage("Temperature;SOC;ChargeRate");
		for (SenderParam sendData : streamData) {
			log.setMessage(sendData.temperature + ";" + sendData.stateOfCharge + ";" + sendData.chargeRate);
		}
	}

	private Float getRandom(Float min, Float max) {
		float rounded = Math.round(((Math.random() * (max - min)) + min) * 100);
		return (float) (rounded / 100.0);
	}

	private int getRandomValue(int maxValue, int minValue) {
		return random.nextInt(maxValue - minValue) + minValue;
	}

}