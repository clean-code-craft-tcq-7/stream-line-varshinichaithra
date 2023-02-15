package Sender;

public class SenderParam {

	public int temperature;
	public int stateOfCharge;
	public float chargeRate;

	public SenderParam(int temperature, int soc, float chargeRate) {
		this.temperature = temperature;
		this.stateOfCharge = soc;
		this.chargeRate = chargeRate;
	}
}