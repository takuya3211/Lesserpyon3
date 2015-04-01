#include "kyokumen.h"

void Te::FPrint(FILE *fp)
{
	fprintf(fp,"%02x",to);
	fprintf(fp,"%02s",komaStr2[koma]);
	if (promote) {
		fprintf(fp,"成");
	}
	if (from<OU) {
		fprintf(fp,"打　");
	} else {
		fprintf(fp,"(%02x)",from);
	}
	if (!promote) {
		fprintf(fp,"　");
	}
}

Te::Te(int SorE,unsigned char f,unsigned char t,const Kyokumen &k)
{
	if (f>100) {
		koma=(f-100)+SorE;
		from=0;
	} else {
        int fd = (f + 8) / 9;
        int fs = (f - 1) % 9 + 1;
		from=fs*16+fd;
		koma=k.ban[from];
	}
	if (t>100) {
		t=t-100;
		promote=1;
	} else {
		promote=0;
	}
    int td = (t + 8) / 9;
    int ts = (t - 1) % 9 + 1;
	to=ts*16+td;
	capture=k.ban[to];
	Kind=0;
	value=0;
}
