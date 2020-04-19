// https://www.shadertoy.com/view/XsyyzW
// Pi by Plouffe spigot algorithm:
// See also (en & fr) https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula
// Adapted from C code:  http://www.experimentalmath.info/bbp-codes/piqpr8.c
// Another PI method (not parallel): https://www.shadertoy.com/view/MdtXWj

#define double float
#define pow16(x) exp2(4.*(x))

// expm = 16^p mod ak.
// This routine uses the left-to-right binary exponentiation scheme.
double expm(double p, double ak) {
  int i, j;
  double p1, pt, r;
#define ntp 25
#define tp(i) exp2(float(i))
  if (ak == 1.) return 0.;

  // Find the greatest power of two less than or equal to p.
  // $FaN: why not using floor(log2(p)) ?
  for (i = 0; i < ntp; i++)
      if (tp(i) > p) break;

  pt = tp(i-1);
  p1 = p;
  r = 1.;
  // Perform binary exponentiation algorithm modulo ak.
  for (j = 1; j <= i; j++){
    if (p1 >= pt){
      r = 16. * r;
      r = mod(r,ak); // $FaN: is mod reliable ?
      p1 -= pt;
    }
    pt /= 2.;
    if (pt >= 1.){
      r = r * r;
      r = mod(r,ak);
    }
  }
  return r;
}

// This routine evaluates the series  sum_k 16^(id-k)/(8*k+m)
// using the modular exponentiation technique.
double series(int m, int id) {
  int k;
  double ak, p, s, t;
#define eps 1e-17 // maybe we could shorten it when using floats
  s = 0.;

  // Sum the series up to id.
  for (k = 0; k < id; k++){
    ak = float(8 * k + m);
    p = float(id - k);
    t = expm (p, ak) / ak;
    s = fract(s+t);
  }

  // Compute a few terms where k >= id.
#define M 8  // was 100. 8 seems sufficient to have the whole 10 hex digit ok ! 1 is still ok for 3 digits
  for (k = id; k <= id + M; k++){
    ak = float(8 * k + m);
    t = pow16( float(id - k)) / ak;
    if (t < eps) break;
    s = fract(s+t);
  }
  return s;
}

// id is the digit position. Digits generated follow immediately after id.
float digit(int id) {
  if (id<0) return .1415926535897; // for test ( = ref )
  double s1 = series(1, id);
  double s2 = series(4, id);
  double s3 = series(5, id);
  double s4 = series(6, id);
  double pid = 4. * s1 - 2. * s2 - s3 - s4;
  return fract(pid);// NB: pid always <0 ?
}

vec2 S = 32./vec2(2,1);             // character size
#define W ivec2(iResolution.xy/S)   // size of display char matrix

void mainImage( out vec4 O, vec2 U ) {
    ivec2 iU = ivec2(U); // cell index
    if ( iU.x>=W.x || iU.y>=W.y ) return;

    // Since only the fractional part is accurate,
    // extracting the wanted digit requires that one removes
    // the integer part of the final sum and multiplies by 16
    // to "skim off" the hexadecimal digit at this position
    // (in theory, the next few digits up to the accuracy of
    // the calculations used would also be accurate).
    //float r = 16. * digit(0 + iU.x + W.x*iU.y);
    float r = digit(0 + iU.x + W.x*iU.y);
    float g = fract(100. * r);
    float b = fract(100. * g);

    O = vec4(r,g,b,1);
}
