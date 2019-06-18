#include "Sprite.h"
#include "myFunction.h"

extern LPDIRECT3DDEVICE9 g_pd3dDevice;
extern LPD3DXSPRITE g_pSprite;


CSprite::CSprite(const char *path) :IObject()
{
	pTexture = LoadTexture(path);
	D3DSURFACE_DESC desc;
	pTexture->GetLevelDesc(0, &desc);
	width = desc.Width;
	height = desc.Height;
	

	rect.left = 0;
	rect.top = 0;
	rect.right = width;
	rect.bottom = height;

	opacity = red = green = blue = 255;
	blendMode = false;

}


CSprite::~CSprite()
{

}


void CSprite::Update(float eTime)
{

}

void CSprite::Render(D3DXMATRIX *pmat)
{
	IObject::Render(pmat);
	g_pSprite->SetTransform(&mat);
	g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	if (blendMode)
	{
		g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
		g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
		g_pd3dDevice->SetRenderState(D3DRS_BLENDOP,D3DBLENDOP_ADD);
	}

	g_pSprite->Draw(pTexture, &rect,NULL,NULL,D3DCOLOR_ARGB(opacity,red,green,blue));
	g_pSprite->End();

}