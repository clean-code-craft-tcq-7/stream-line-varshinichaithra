package TestSender;



import static org.junit.Assert.*;
import org.junit.Test;

import Sender.SenderData;
import Sender.SenderParam;
import Sender.SenderService;
import Sender.SenderServiceImpl;


public class TestSenderData {

	// validate whether Data send is null then return null
	@Test
	public void givenBatteryParametersAsNull() {
		SenderParam batteryValue = null;
		assertNull(SenderData.isEmpty(batteryValue));
	}

	// validate Data send in stream hat atleast 10 values
	@Test
	public void givenBatteryParametersSizeisLessThan10() {
		assertFalse(SenderData.validateDataSize("5"));
	}

	// validate Data send has valid size then read the Data and print in console
	@Test
	public void givenBatteryParamexpectspropercount() {
		SenderService sender = new SenderServiceImpl();
		int validateSize = 50;
		assertEquals(sender.receiveReadingsFromBattery(50).size(), validateSize);
		sender.sendReadingsToConsole();
	}

}

