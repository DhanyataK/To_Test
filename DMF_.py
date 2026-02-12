#begin SubmodelEditorSubmodelSetter
AMEChangeSubmodel("DMF", "TRDMF0C", "$AME/libtr/submodels", False, False, None)
#UpdateBatchConfiguration
#Update sensor connections
#Update post-processed variables
#Update units manager
#Update export setup
#Update cross variables
#end SubmodelEditorSubmodelSetter
AMESetParameterValue("damp@DMF", "1", None)
AMESetParameterValue("damp@DMF", "0.1", None)
AMESetParameterValue("damp@DMF", "0.8", None)
AMESetParameterValue("gap1@DMF", "0", None)
ApplyUpdateAssistant(SC('DMF_1a549ae7c45c4739aad6ebc3a0f97dc6'))
