package com.example.dope.universalrefillapplication;

import android.os.AsyncTask;

/**
 * Created by Dope on 1/17/2018.
 */

abstract class serverConnection extends AsyncTask<String, Void, String> {

    @Override
    protected String doInBackground(String... params)
    {
        onPostExecute();
    }

    @Override
    protected void onPostExecute(String result)
    {

    }

    @Override
    protected void onPreExecute()
    {

    }

    @Override
    protected void onProgressUpdate(Void... values)
    {

    }
}


