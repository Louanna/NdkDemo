package com.ndk.demo;

/**
 * Created by anna on 2017/11/8.
 */

public class One {
    // Used to load the 'one-lib' library on application startup.
    static {
        System.loadLibrary("one-lib");
    }

    /**
     * A native method that is implemented by the 'one-lib' native library,
     * which is packaged with this application.
     */
    public native void stringFromOneLibrary();
}
