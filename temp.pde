  // COLOR CALCULATIONS

  // Given input values for coloring, these functions will fill the calcXxxx
  // variables with values that have been properly filtered through the
  // current colorMode settings.

  // Renderers that need to subclass any drawing properties such as fill or
  // stroke will usally want to override methods like fillFromCalc (or the
  // same for stroke, ambient, etc.) That way the color calcuations are
  // covered by this based PGraphics class, leaving only a single function
  // to override/implement in the subclass.


  /**
   * Set the fill to either a grayscale value or an ARGB int.
   * <P>
   * The problem with this code is that it has to detect between these two
   * situations automatically. This is done by checking to see if the high bits
   * (the alpha for 0xAA000000) is set, and if not, whether the color value
   * that follows is less than colorModeX (first param passed to colorMode).
   * <P>
   * This auto-detect would break in the following situation:
   * <PRE>size(256, 256);
   * for (int i = 0; i < 256; i++) {
   *   color c = color(0, 0, 0, i);
   *   stroke(c);
   *   line(i, 0, i, 256);
   * }</PRE>
   * ...on the first time through the loop, where (i == 0), since the color
   * itself is zero (black) then it would appear indistinguishable from code
   * that reads "fill(0)". The solution is to use the four parameter versions
   * of stroke or fill to more directly specify the desired result.
   */
  protected void colorCalc(int rgb) {
    if (((rgb & 0xff000000) == 0) && (rgb <= colorModeX)) {
      colorCalc((float) rgb);

    } else {
      colorCalcARGB(rgb, colorModeA);
    }
  }


  protected void colorCalc(int rgb, float alpha) {
    if (((rgb & 0xff000000) == 0) && (rgb <= colorModeX)) {  // see above
      colorCalc((float) rgb, alpha);

    } else {
      colorCalcARGB(rgb, alpha);
    }
  }


  protected void colorCalc(float gray) {
    colorCalc(gray, colorModeA);
  }


  protected void colorCalc(float gray, float alpha) {
    if (gray > colorModeX) gray = colorModeX;
    if (alpha > colorModeA) alpha = colorModeA;

    if (gray < 0) gray = 0;
    if (alpha < 0) alpha = 0;

    calcR = colorModeScale ? (gray / colorModeX) : gray;
    calcG = calcR;
    calcB = calcR;
    calcA = colorModeScale ? (alpha / colorModeA) : alpha;

    calcRi = (int)(calcR*255); calcGi = (int)(calcG*255);
    calcBi = (int)(calcB*255); calcAi = (int)(calcA*255);
    calcColor = (calcAi << 24) | (calcRi << 16) | (calcGi << 8) | calcBi;
    calcAlpha = (calcAi != 255);
  }


  protected void colorCalc(float x, float y, float z) {
    colorCalc(x, y, z, colorModeA);
  }


  protected void colorCalc(float x, float y, float z, float a) {
    if (x > colorModeX) x = colorModeX;
    if (y > colorModeY) y = colorModeY;
    if (z > colorModeZ) z = colorModeZ;
    if (a > colorModeA) a = colorModeA;

    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (z < 0) z = 0;
    if (a < 0) a = 0;

    switch (colorMode) {
    case RGB:
      if (colorModeScale) {
        calcR = x / colorModeX;
        calcG = y / colorModeY;
        calcB = z / colorModeZ;
        calcA = a / colorModeA;
      } else {
        calcR = x; calcG = y; calcB = z; calcA = a;
      }
      break;

    case HSB:
      x /= colorModeX; // h
      y /= colorModeY; // s
      z /= colorModeZ; // b

      calcA = colorModeScale ? (a/colorModeA) : a;

      if (y == 0) {  // saturation == 0
        calcR = calcG = calcB = z;

      } else {
        float which = (x - (int)x) * 6.0f;
        float f = which - (int)which;
        float p = z * (1.0f - y);
        float q = z * (1.0f - y * f);
        float t = z * (1.0f - (y * (1.0f - f)));

        switch ((int)which) {
        case 0: calcR = z; calcG = t; calcB = p; break;
        case 1: calcR = q; calcG = z; calcB = p; break;
        case 2: calcR = p; calcG = z; calcB = t; break;
        case 3: calcR = p; calcG = q; calcB = z; break;
        case 4: calcR = t; calcG = p; calcB = z; break;
        case 5: calcR = z; calcG = p; calcB = q; break;
        }
      }
      break;
    }
    calcRi = (int)(255*calcR); calcGi = (int)(255*calcG);
    calcBi = (int)(255*calcB); calcAi = (int)(255*calcA);
    calcColor = (calcAi << 24) | (calcRi << 16) | (calcGi << 8) | calcBi;
    calcAlpha = (calcAi != 255);
  }


  /**
   * Unpacks AARRGGBB color for direct use with colorCalc.
   * <P>
   * Handled here with its own function since this is indepenent
   * of the color mode.
   * <P>
   * Strangely the old version of this code ignored the alpha
   * value. not sure if that was a bug or what.
   * <P>
   * Note, no need for a bounds check for 'argb' since it's a 32 bit number.
   * Bounds now checked on alpha, however (rev 0225).
   */
  protected void colorCalcARGB(int argb, float alpha) {
    if (alpha == colorModeA) {
      calcAi = (argb >> 24) & 0xff;
      calcColor = argb;
    } else {
      calcAi = (int) (((argb >> 24) & 0xff) * PApplet.constrain((alpha / colorModeA), 0, 1));
      calcColor = (calcAi << 24) | (argb & 0xFFFFFF);
    }
    calcRi = (argb >> 16) & 0xff;
    calcGi = (argb >> 8) & 0xff;
    calcBi = argb & 0xff;
    calcA = calcAi / 255.0f;
    calcR = calcRi / 255.0f;
    calcG = calcGi / 255.0f;
    calcB = calcBi / 255.0f;
    calcAlpha = (calcAi != 255);
  }



  //////////////////////////////////////////////////////////////

  // COLOR DATATYPE STUFFING

  // The 'color' primitive type in Processing syntax is in fact a 32-bit int.
  // These functions handle stuffing color values into a 32-bit cage based
  // on the current colorMode settings.

  // These functions are really slow (because they take the current colorMode
  // into account), but they're easy to use. Advanced users can write their
  // own bit shifting operations to setup 'color' data types.


  public final int color(int c) {  // ignore
//    if (((c & 0xff000000) == 0) && (c <= colorModeX)) {
//      if (colorModeDefault) {
//        // bounds checking to make sure the numbers aren't to high or low
//        if (c > 255) c = 255; else if (c < 0) c = 0;
//        return 0xff000000 | (c << 16) | (c << 8) | c;
//      } else {
//        colorCalc(c);
//      }
//    } else {
//      colorCalcARGB(c, colorModeA);
//    }
    colorCalc(c);
    return calcColor;
  }


  public final int color(float gray) {  // ignore
    colorCalc(gray);
    return calcColor;
  }


  /**
   * @param c can be packed ARGB or a gray in this case
   */
  public final int color(int c, int alpha) {  // ignore
//    if (colorModeDefault) {
//      // bounds checking to make sure the numbers aren't to high or low
//      if (c > 255) c = 255; else if (c < 0) c = 0;
//      if (alpha > 255) alpha = 255; else if (alpha < 0) alpha = 0;
//
//      return ((alpha & 0xff) << 24) | (c << 16) | (c << 8) | c;
//    }
    colorCalc(c, alpha);
    return calcColor;
  }


  /**
   * @param c can be packed ARGB or a gray in this case
   */
  public final int color(int c, float alpha) {  // ignore
//    if (((c & 0xff000000) == 0) && (c <= colorModeX)) {
    colorCalc(c, alpha);
//  } else {
//    colorCalcARGB(c, alpha);
//  }
    return calcColor;
  }


  public final int color(float gray, float alpha) {  // ignore
    colorCalc(gray, alpha);
    return calcColor;
  }


  public final int color(int v1, int v2, int v3) {  // ignore
    colorCalc(v1, v2, v3);
    return calcColor;
  }


  public final int color(float v1, float v2, float v3) {  // ignore
    colorCalc(v1, v2, v3);
    return calcColor;
  }


  public final int color(int v1, int v2, int v3, int a) {  // ignore
    colorCalc(v1, v2, v3, a);
    return calcColor;
  }


  public final int color(float v1, float v2, float v3, float a) {  // ignore
    colorCalc(v1, v2, v3, a);
    return calcColor;
  }