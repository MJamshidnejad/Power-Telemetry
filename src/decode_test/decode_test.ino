void setup() {
  Serial.begin(115200);

  Serial.print( decode7to8bit("60546072606460F26074"));

}

void loop() {}

String decode7to8bit(String str) {
  byte data8bit[160];
  byte data7bit[140];
  byte len = str.length();
  int lsb, msb;
  for ( int i = 0, j = 0; i < len; i += 2, j++) {
    msb = tolower(str[i]);
    lsb = tolower(str [i + 1]);
    msb -= isdigit(msb) ? 0x30 : 0x57;
    lsb -= isdigit(lsb) ? 0x30 : 0x57;
    data7bit[j] = (char)(lsb | (msb << 4));
  }

  str = "";

  for (byte i = 0, counter = 0, j = 0; i < len / 2; i++, counter++, j++) {
    byte current = data7bit[i];
    byte previous = i == 0 ? 0 : data7bit[i - 1];
    if (counter == 7)  counter = 0;

    int shiftedCurrent = (current << counter) & 0x7F;

    int shiftedPrevious = (previous & 0xFF) >> (8 - counter);
    data8bit[j] = (shiftedCurrent | shiftedPrevious);
    str += char(data8bit[j]);
    if (counter == 6) {
      j++;
      data8bit[j] = ((current & 0xFF) >> 1);
      str += char(data8bit[j]);
    }
  }
  return str;
}
