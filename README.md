



### Third party installs

installed *nupengl.core v0.1.0.1* via NuGet Package Manager

installed *SOIL v1.16.0* via NuGet Package Manager


### Troubleshooting

"LNK2019: unresolved external symbol" - Check if there is a red-minus on file in explorer. If so, add file to project.

PNG silently fails to show up if "interlaced" - Ensure images are NOT interlaced.

"LNK2019: unresolved external symbol" - Remove "inline" from methods. VS auto-adds this when refactoring but it causes linker problems.
