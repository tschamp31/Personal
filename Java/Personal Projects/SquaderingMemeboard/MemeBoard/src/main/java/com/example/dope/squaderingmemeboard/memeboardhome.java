package com.example.dope.squaderingmemeboard;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.print.PrintAttributes;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.text.style.DrawableMarginSpan;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.Space;


import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.MobileAds;

import java.lang.reflect.Field;


public class memeboardhome extends AppCompatActivity
{
    private AdView mAdView;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        Toolbar toolbar = findViewById(R.id.toolbar);
        //mAdView = findViewById(R.id.adView);
        //MobileAds.initialize(this, "ca-app-pub-3870518248253183~4871266500");
        Field[] fields = R.raw.class.getFields();
        int soundtotal = fields.length;

        //final Button dawaebutton = findViewById(R.id.dawaeButton);
        //final Button mlgairhornButton = findViewById(R.id.mlgairhornButton);
        //final Button mlghitButton = findViewById(R.id.mlghitButton);
        //final Button assmuncherButton = findViewById(R.id.assmuncherButton);
        final Intent soundname = new Intent();
        soundname.setAction("com.example.dope.squaderingmemeboard");

        final LinearLayout box = new LinearLayout(this);
        box.setOrientation(LinearLayout.VERTICAL);
        box.setBackgroundColor(Color.parseColor("black"));


        for(int count=1; count < (soundtotal + 1); count++)
        {
            LinearLayout row = new LinearLayout(this);

            LinearLayout.LayoutParams rowStyle = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.FILL_PARENT, 1.0f);
            rowStyle.setMargins(10,10,10,10);

            row.setId(count * 3);
            box.addView(row, rowStyle);

            for(int buttonPerRow = 0; buttonPerRow < 3; buttonPerRow++)
            {
                Button button = new Button(this);
                button.setLayoutParams(new LinearLayout.LayoutParams(0, LinearLayout.LayoutParams.FILL_PARENT, 1.0f));
                button.setText(fields[count - 1].getName());
                button.setBackgroundColor(Color.parseColor("#FF9800"));
                button.setId(count * 5);
                row.addView(button, rowStyle);
            }

        }

        super.setContentView(box);

        /*for reference remove later
        CheckBox checkbox = new CheckBox(this);
        checkbox.setText(fields[count].getName());
        ll.addView(checkbox);
        */


        //AdRequest adRequest = new AdRequest.Builder().build();
        //mAdView.loadAd(adRequest);

/*
        dawaebutton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                soundname.putExtra("soundname","dawae");
                memeboardhome.this.sendBroadcast(soundname);
            }
        });

        mlgairhornButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                soundname.putExtra("soundname","mlgairhorn");
                memeboardhome.this.sendBroadcast(soundname);
            }
        });

        mlghitButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                soundname.putExtra("soundname","mlghit");
                memeboardhome.this.sendBroadcast(soundname);
            }
        });

        assmuncherButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                soundname.putExtra("soundname","assmuncher");
                memeboardhome.this.sendBroadcast(soundname);
            }
        });
*/


        setSupportActionBar(toolbar);

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_memeboardhome, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
