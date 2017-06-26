import java.util.*;
public class TestJni{
	public native int linux_main();
	static{
		System.loadLibrary("TestJni");
	}
}
