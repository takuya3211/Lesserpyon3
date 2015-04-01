#ifndef _MAIN_H_
#define _MAIN_H_

#include <algorithm>
#include <stdio.h>

#include "kyokumen.h"

#define MAX_DEPTH 32
#define VAL_INFINITE  999999

enum {
	EXACTLY_VALUE,		// 値は局面の評価値そのもの
	LOWER_BOUND,		// 値は局面の評価値の下限値(val>=β)
	UPPER_BOUND			// 値は局面の評価値の上限値(val<=α)
};


class HashEntry {
public:
	uint64 HashVal;		// ハッシュ値
	Te Best;			// 前回の反復深化での最善手
	Te Second;			// 前々回以前の反復深化での最善手
	int value;			// αβ探索で得た局面の評価値
	int flag;			// αβ探索で得た値が、局面の評価値そのものか、上限値か下限値か
	int Tesu;			// αβ探索を行った際の手数
	short depth;		// αβ探索を行った際の深さ
	short remainDepth;	// αβ探索を行った際の残り深さ
};


// 思考ルーチンです。
class Sikou {
protected:
	static HashEntry HashTbl[1024*1024];	// 20bitの大きさ、40Mバイト
	int MakeMoveFirst(int SorE,int depth,Te teBuf[],KyokumenKomagumi k);
public:
	// とりあえず、何らかの局面を与えて手を返す関数です。
	Te Think(int SorE,KyokumenKomagumi k);
	// 第４章で追加。ある深さでの最善手を保持する。
	Te Best[MAX_DEPTH][MAX_DEPTH];
	int MinMax(int SorE,KyokumenKomagumi &k,int depth,int depthMax);
	int AlphaBeta(int SorE,KyokumenKomagumi &k,int alpha,int beta,int depth,int depthMax);
	int NegaAlphaBeta(int SorE,KyokumenKomagumi &k,int alpha,int beta,int depth,int depthMax,bool bITDeep=true);
	int ITDeep(int SorE,KyokumenKomagumi &k,int alpha,int beta,int depth,int depthMax);	// NegaAlphaBetaを用いた反復深化
};
#endif
