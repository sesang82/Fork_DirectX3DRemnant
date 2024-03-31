#pragma once
#include "CRenderComponent.h"
#include "CMeshData.h"
#include "ptr.h"
// 목표
// 빈 게임오브젝트에서 메쉬 머티리얼 세팅 되도록 보안하기


class CMeshRender :
    public CRenderComponent
{
private:
    Ptr<CMeshData>  m_meshData;
    bool            m_bRenderOff;

public:
    virtual void finaltick() override;
    virtual void render() override;
    virtual void render(UINT _iSubset) override;

public:
    void SetMeshData(Ptr<CMeshData> _meshData);
    Ptr<CMeshData> GetMeshData() { return m_meshData; }

    void SetRenderOff(bool _is) { m_bRenderOff = _is; }

    virtual void SaveToLevelFile(FILE* _File) override;
    virtual void LoadFromLevelFile(FILE* _File) override;

    CLONE(CMeshRender);
public:
    CMeshRender();
    ~CMeshRender();
};

