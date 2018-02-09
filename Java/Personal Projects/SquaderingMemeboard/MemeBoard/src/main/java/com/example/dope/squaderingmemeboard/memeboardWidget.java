package com.example.dope.squaderingmemeboard;

import android.app.PendingIntent;
import android.appwidget.AppWidgetManager;
import android.appwidget.AppWidgetProvider;
import android.content.Context;
import android.content.Intent;
import android.widget.Button;
import android.widget.RemoteViews;

/**
 * Implementation of App Widget functionality.
 * App Widget Configuration implemented in {@link memeboardWidgetConfigureActivity memeboardWidgetConfigureActivity}
 */
public class memeboardWidget extends AppWidgetProvider {

    @Override
    public void onUpdate(Context context, AppWidgetManager appWidgetManager, int[] appWidgetIds) {
        // There may be multiple widgets active, so update all of them

        for (int appWidgetId : appWidgetIds)
        {
            RemoteViews views = new RemoteViews(context.getPackageName(), R.layout.memeboard_widget);

            views.setOnClickPendingIntent(buttonID(context, "dawae"), pendingIntent(context, "dawae", 1));
            views.setOnClickPendingIntent(buttonID(context, "mlgairhorn"), pendingIntent(context, "mlgairhorn", 2));
            views.setOnClickPendingIntent(buttonID(context, "mlghit"), pendingIntent(context, "mlghit", 3));
            views.setOnClickPendingIntent(buttonID(context, "assmuncher"), pendingIntent(context, "assmuncher", 4));


            appWidgetManager.updateAppWidget(appWidgetId, views);
        }

    }


    //returns button id of "R.id.button" by string name
    protected int buttonID(Context context, String soundname)
    {
        int id;
        String buttonname = soundname + "Button" + "Widget";
        id = 0;


        return id;
    }

    protected PendingIntent pendingIntent(Context context, String soundname, int requestcode) {
        Intent intent = new Intent();
        intent.setAction("com.example.dope.squaderingmemeboard");
        intent.putExtra("soundname", soundname);
        return PendingIntent.getBroadcast(context, requestcode, intent, 0);
    }

    @Override
    public void onDeleted(Context context, int[] appWidgetIds) {
        // When the user deletes the widget, delete the preference associated with it.
        for (int appWidgetId : appWidgetIds) {
        }
    }

    @Override
    public void onEnabled(Context context) {
        // Enter relevant functionality for when the first widget is created
    }

    @Override
    public void onDisabled(Context context) {
        // Enter relevant functionality for when the last widget is disabled
    }

}

