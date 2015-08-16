# Misc

# Delete all objects, dependencies and binaries
clean:
	@$(CLEAN)

# Print local variable values
print:
	@$(foreach V,$(sort $(.VARIABLES)), \
	$(if $(filter-out environment% default automatic, \
	$(origin $V)),$(warning $V=$($V))))

# Print local variable values and statements
printall:
	@$(foreach V,$(sort $(.VARIABLES)), \
	$(if $(filter-out environment% default automatic, \
	$(origin $V)),$(warning $V=$($V) ($(value $V)))))
