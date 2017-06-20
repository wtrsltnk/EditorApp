// WorkspaceToolBox.cpp: implementation of the WorkspaceToolBox class.
//
//////////////////////////////////////////////////////////////////////

#include "WorkspaceToolBox.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WorkspaceToolBox::WorkspaceToolBox()
{
	this->m_dwResource = IDD_WORKSPACE;
	this->document = 0;
	this->workspaceMenu.AddItem("Add Model", ID_ADD_MODEL);
	this->modelMenu.AddItem("Add Meshgroup", ID_ADD_MESHGROUP);
	this->modelMenu.AddItem("Add Meshgroup", ID_ADD_SEQUENCE);
	this->meshgroupMenu.AddItem("Add Mesh", ID_ADD_MESH);
}

WorkspaceToolBox::~WorkspaceToolBox()
{
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
LRESULT WorkspaceToolBox::ViewProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		{
			this->view = new CWTreeView();
			this->view->Create(this->m_Dialog.GetItem(IDC_WORKSPACE));

			InitView();
			break;
		}

	case WM_NOTIFY:
		{
			switch (((LPNMHDR) lParam)->code)
			{
			case NM_RCLICK:
				{
					POINT pt;
					GetCursorPos(&pt);
					GetMenu()->ShowMenu(this->m_hWnd, pt.x, pt.y);
					break; 
				}

			case NM_DBLCLK:
			case NM_RETURN:
				{
					if (this->document)
					{
						Workspace* ws = this->document->GetWorkspace();

						if (ws)
						{
							LPARAM data = this->view->GetItemData(this->view->GetSelectedItem());
                            const char* title = this->view->GetItemText(this->view->GetSelectedItem());

							switch ((ItemTypes)data)
							{
							case eTitle:
							case eWorkspace:
							case eSkeleton:
							case eMeshGroup:
								{
									break;
								}
							case eModel:
								{
									ws->SetCurrentModel(title);
									this->document->Render();
									break;
								}
							case eSequence:
								{
									HTREEITEM seq = this->view->GetSelectedItem();
									HTREEITEM seqtitle = this->view->GetParentItem(seq);
									HTREEITEM mdl = this->view->GetParentItem(seqtitle);
                                    const char* mdlname = this->view->GetItemText(mdl);

									if (Model* model = ws->GetModel(mdlname))
									{
										model->SetCurrentSequence(this->view->GetItemText(seq));
										this->document->Render();
									}
									break;
								}
							case eMesh:
								{
									HTREEITEM msh = this->view->GetSelectedItem();
									HTREEITEM grp = this->view->GetParentItem(msh);
                                    const char* grpname = this->view->GetItemText(grp);
									HTREEITEM grptitle = this->view->GetParentItem(grp);
									HTREEITEM mdl = this->view->GetParentItem(grptitle);
                                    const char* mdlname = this->view->GetItemText(mdl);

									if (Model* model = ws->GetModel(mdlname))
									{
										if (MeshGroup* meshgroup = model->GetMeshGroup(grpname))
										{
                                            const char* mesh = this->view->GetItemText(msh);
											meshgroup->SetCurrentMesh(mesh);
											this->document->Render();
										}
									}
									break;
								}
							}
						}
					}
					break;
				}
			}
			break; 
		}

	case WM_COMMAND:
		{
			switch (wParam)
			{
			case ID_ADD_MODEL:
				{
					break;
				}
			case ID_ADD_MESHGROUP:
				{
					break;
				}

			case ID_ADD_SEQUENCE:
				{
					break;
				}

			case ID_ADD_MESH:
				{
					break;
				}
			}
			break;
		}
	
	}
	return CWToolBox::ViewProc(uMsg, wParam, lParam);
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
CWPopUpMenu* WorkspaceToolBox::GetMenu()
{
	return &this->workspaceMenu;
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void WorkspaceToolBox::InitView()
{
    static char TMP_STR[1024] = { 0 };
	this->view->ClearItems();

	Workspace* ws = this->document->GetWorkspace();
	if (ws)
	{
		HTREEITEM wst = this->view->AddItem(ws->Name(), TVGN_ROOT, 0, 0, (LPARAM)eWorkspace);

		for (int i = 0; i < ws->GetModelCount(); i++)
		{
			Model* model = ws->GetModel(i);
            strcpy(TMP_STR, model->Name());
            HTREEITEM mdl = this->view->AddItem(TMP_STR, wst, 0, 0, (LPARAM)eModel);

			if (Skeleton* skeleton = model->GetSkeleton())
			{
				HTREEITEM sk = this->view->AddItem("Skeleton", mdl, 0, 0, (LPARAM)eSkeleton);
				for (int ii = 0; ii < skeleton->GetJointCount(); ii++)
				{
					char bn[32] = {0};
					Joint* joint = skeleton->GetJoint(ii);
					sprintf(bn, "Joint%2.2i (%2.2i)", joint->ID(), joint->Parent());
					this->view->AddItem(bn, sk);
				}
			}

			HTREEITEM mg = this->view->AddItem("MeshGroups", mdl, 0, 0, (LPARAM)eTitle);
			for (int j = 0; j < model->GetMeshGroupCount(); j++)
			{
				MeshGroup* meshgroup = model->GetMeshGroup(j);
                strcpy(TMP_STR, meshgroup->Name());
                HTREEITEM mgn = this->view->AddItem(TMP_STR, mg, 0, 0, (LPARAM)eMeshGroup);

				for (int jj = 0; jj < meshgroup->GetMeshCount(); jj++)
				{
					Mesh* mesh = meshgroup->GetMesh(jj);
                    strcpy(TMP_STR, mesh->Name());
                    this->view->AddItem(TMP_STR, mgn, 0, 0, (LPARAM)eMesh);
				}
			}
			this->view->Expand(mg);

			HTREEITEM seq = this->view->AddItem("Sequences", mdl, 0, 0, (LPARAM)eTitle);
			for (int k = 0; k < model->GetSequenceCount(); k++)
			{
				Sequence* sequence = model->GetSequence(k);
                strcpy(TMP_STR, sequence->Name());
                HTREEITEM sqn = this->view->AddItem(TMP_STR, seq, 0, 0, (LPARAM)eSequence);
			}
			this->view->Expand(seq);

			this->view->Expand(mdl);
		}
		this->view->Expand(wst);
	}
}

//////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
//////////////////////////////////////////////////////////////////////
void WorkspaceToolBox::SetDocument(Document* document)
{
	this->document = document;
}
