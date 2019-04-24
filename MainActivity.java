package developer.omkardeshmukh.firebaseled;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class MainActivity extends AppCompatActivity {

    Button buttonSwitchOn, buttonSwitchOff;

    private DatabaseReference databaseReference;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        buttonSwitchOn = findViewById(R.id.button_switch_on);
        buttonSwitchOff = findViewById(R.id.button_switch_off);

        databaseReference = FirebaseDatabase.getInstance().getReference();

        final DatabaseReference databaseReference1 = databaseReference.child("led");

        buttonSwitchOn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                databaseReference1.setValue(1);
            }
        });

        buttonSwitchOff.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                databaseReference1.setValue(0);
            }
        });
    }
}
