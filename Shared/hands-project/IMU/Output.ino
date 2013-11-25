/* This file is part of the Razor AHRS Firmware */

// Output angles: yaw, pitch, roll
void output_angles()
{
  if (output_format == OUTPUT__FORMAT_BINARY)
  {
    float ypr[3];  
    ypr[0] = TO_DEG(yaw);
    ypr[1] = TO_DEG(pitch);
    ypr[2] = TO_DEG(roll);
    Serial.write((byte*) ypr, 12);  // No new-line
  }
  else if (output_format == OUTPUT__FORMAT_TEXT)
  {
    //Serial.print("#YPR=");
    Serial.print(TO_DEG(yaw)); Serial.print(",");
    Serial.print(TO_DEG(pitch)); Serial.print(",");
    Serial.print(TO_DEG(roll)); Serial.println();
  }
}

void output_acc_in_local_frame()
{
   if (output_format == OUTPUT__FORMAT_TEXT)
  {
    float c1 = cos(roll);
    float s1 = sin(roll);
    float c2 = cos(pitch);
    float s2 = sin(pitch);
    float c3 = cos(yaw);
    float s3 = sin(yaw);
    

    //float accel_x=accel[1]*c1-accel[2]*s1;   // Roll
    //float accel_x=accel[1];
    float accel_x=accel[1]*c1-s1*s2*accel[0]-s1*c2*accel[2];  //Roll*Pitch
    //float accel_x=accel[1]*c3-accel[0]*s3; //Yaw
    //float accel_x=accel[1]*(c1*c3+s1*s2*s3)+accel[0]*(c1*s3-s1*s2*c3)+accel[2]*(-s1*c2); //Roll*Pitch*Yaw
    //float accel_x=accel[1]*(c1*c3)+accel[0]*(-s1*s2*c3-c2*s3)+accel[2]*(-s1*c2*c3-s2*s3); //Yaw*Roll*Pitch
    float accel_x1=accel[1]*c1-accel[2]*s1; // Pitch*Roll
    //float actaccel_x = kalmanCalculate(accel_x, accel_x1, lastLoopTime);       
    //float accel_y=accel[0];
    float accel_y=accel[0]*c2+accel[2]*s2;   //Pitch || Roll*Pitch
    //float accel_y=accel[1]*s3+accel[0]*c3; // Yaw
    //float accel_y=accel[1]*(-c2*s3)+accel[0]*(c2*c3)+accel[2]*s2;  //Roll*Pitch*Yaw
    //float accel_y=accel[1]*(c1*s3)+accel[0]*(-s1*s2*s3+c2*c3)+accel[2]*(-s1*c2*s3+s2*c3);  //Yaw*Roll*Pitch
    //float accel_z=accel[1]*s1+accel[2]*c1; // Roll
    //float accel_z=-accel[1]*s2+accel[2]*c2;  //Pitch
    float accel_z=accel[1]*s1-s2*c1*accel[0]+c1*c2*accel[2]-256; //Roll*Pitch
    //float accel_z=accel[2];
    //float accel_z=accel[1]*(s1*c3+c1*s2*s3)+accel[0]*(s1*s3-c1*s2*c3)+accel[2]*(c2*c1);  //Roll*Pitch*Yaw
    //float accel_z=accel[1]*s1+accel[0]*(-c1*s2)+accel[2]*(c2*c1)-256;  //Roll*Pitch*Yaw
    


    //Serial.print("#XYZ=");
    Serial.print(accel_x); Serial.print(",");
    Serial.print(accel_x1); Serial.print(",");
    //Serial.print(actaccel_x); Serial.print(",")
    Serial.print(accel_y); Serial.print(",");
    Serial.print(accel_z); Serial.println();
    Serial.println();
  }
  
}


void output_acc_in_global_frame()
{
  if (output_format == OUTPUT__FORMAT_TEXT)
  {
    //Serial.print("#XYZ=");
    Serial.print(y_acceleration[0]); Serial.print(",");
    Serial.print(x_acceleration[0]); Serial.print(",");
    Serial.print(z_acceleration[0]-9.8); Serial.println();
  }
}
void output_calibration(int calibration_sensor)
{
  if (calibration_sensor == 0)  // Accelerometer
  {
    // Output MIN/MAX values
    Serial.print("accel x,y,z (min/max) = ");
    for (int i = 0; i < 3; i++) {
      if (accel[i] < accel_min[i]) accel_min[i] = accel[i];
      if (accel[i] > accel_max[i]) accel_max[i] = accel[i];
      Serial.print(accel_min[i]);
      Serial.print("/");
      Serial.print(accel_max[i]);
      if (i < 2) Serial.print("  ");
      else Serial.println();
    }
  }
  else if (calibration_sensor == 1)  // Magnetometer
  {
    // Output MIN/MAX values
    Serial.print("magn x,y,z (min/max) = ");
    for (int i = 0; i < 3; i++) {
      if (magnetom[i] < magnetom_min[i]) magnetom_min[i] = magnetom[i];
      if (magnetom[i] > magnetom_max[i]) magnetom_max[i] = magnetom[i];
      Serial.print(magnetom_min[i]);
      Serial.print("/");
      Serial.print(magnetom_max[i]);
      if (i < 2) Serial.print("  ");
      else Serial.println();
    }
  }
  else if (calibration_sensor == 2)  // Gyroscope
  {
    // Average gyro values
    for (int i = 0; i < 3; i++)
      gyro_average[i] += gyro[i];
    gyro_num_samples++;
      
    // Output current and averaged gyroscope values
    Serial.print("gyro x,y,z (current/average) = ");
    for (int i = 0; i < 3; i++) {
      Serial.print(gyro[i]);
      Serial.print("/");
      Serial.print(gyro_average[i] / (float) gyro_num_samples);
      if (i < 2) Serial.print("  ");
      else Serial.println();
    }
  }
}

void output_sensors_text(char raw_or_calibrated)
{
  Serial.print("#A-"); Serial.print(raw_or_calibrated); Serial.print('=');
  Serial.print(accel[0]); Serial.print(",");
  Serial.print(accel[1]); Serial.print(",");
  Serial.print(accel[2]); Serial.println();

  Serial.print("#M-"); Serial.print(raw_or_calibrated); Serial.print('=');
  Serial.print(magnetom[0]); Serial.print(",");
  Serial.print(magnetom[1]); Serial.print(",");
  Serial.print(magnetom[2]); Serial.println();

  Serial.print("#G-"); Serial.print(raw_or_calibrated); Serial.print('=');
  Serial.print(gyro[0]); Serial.print(",");
  Serial.print(gyro[1]); Serial.print(",");
  Serial.print(gyro[2]); Serial.println();
}

void output_sensors_binary()
{
  Serial.write((byte*) accel, 12);
  Serial.write((byte*) magnetom, 12);
  Serial.write((byte*) gyro, 12);
}

void output_sensors()
{
  if (output_mode == OUTPUT__MODE_SENSORS_RAW)
  {
    if (output_format == OUTPUT__FORMAT_BINARY)
      output_sensors_binary();
    else if (output_format == OUTPUT__FORMAT_TEXT)
      output_sensors_text('R');
  }
  else if (output_mode == OUTPUT__MODE_SENSORS_CALIB)
  {
    // Apply sensor calibration
    compensate_sensor_errors();
    
    if (output_format == OUTPUT__FORMAT_BINARY)
      output_sensors_binary();
    else if (output_format == OUTPUT__FORMAT_TEXT)
      output_sensors_text('C');
  }
  else if (output_mode == OUTPUT__MODE_SENSORS_BOTH)
  {
    if (output_format == OUTPUT__FORMAT_BINARY)
    {
      output_sensors_binary();
      compensate_sensor_errors();
      output_sensors_binary();
    }
    else if (output_format == OUTPUT__FORMAT_TEXT)
    {
      output_sensors_text('R');
      compensate_sensor_errors();
      output_sensors_text('C');
    }
  }
}

