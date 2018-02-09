package com.example.dope.squaderingmemeboard;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.media.MediaPlayer;
import android.widget.CheckBox;
import android.widget.Toast;

import java.lang.reflect.Field;

/**
 * Created by Dope on 1/29/2018.
 */

public class soundboardReceiver extends BroadcastReceiver
{


    public soundboardReceiver()
    {

    }

    @Override
    public void onReceive(Context context, Intent intent)
    {
        Toast.makeText(context, "broadcast worked", Toast.LENGTH_LONG).show();
        Field[] fields = R.raw.class.getFields();

        final MediaPlayer dawae = MediaPlayer.create(context.getApplicationContext(), R.raw.dawae);
        final MediaPlayer mlgairhorn = MediaPlayer.create(context.getApplicationContext(), R.raw. airhorn);
        final MediaPlayer mlghit = MediaPlayer.create(context.getApplicationContext(), R.raw.mlghit);
        final MediaPlayer assmuncher = MediaPlayer.create(context.getApplicationContext(), R.raw.assmuncher);


        switch(intent.getExtras().getString("soundname"))
        {
            case "dawae":
                dawae.start();
                break;
            case "mlgairhorn":
                mlgairhorn.start();
                break;
            case "mlghit":
                mlghit.start();
                break;
            case "assmuncher":
                assmuncher.start();
                break;
        }
    }
}
