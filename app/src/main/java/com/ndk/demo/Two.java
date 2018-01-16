package com.ndk.demo;

/**
 * Created by anna on 2017/11/8.
 */

public class Two {
    // Used to load the 'one-lib' library on application startup.
    static {
        System.loadLibrary("two-lib");
    }

    /**
     * A native method that is implemented by the 'two-lib' native library,
     * which is packaged with this application.
     */
    public native void stringFromOneLibrary();
}
